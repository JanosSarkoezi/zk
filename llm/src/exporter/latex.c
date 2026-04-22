#include "latex.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

void init_key_list(KeyList *list) {
    list->count = 0;
    list->capacity = 10;
    list->keys = malloc(sizeof(char*) * list->capacity);
}

void add_unique_key(KeyList *list, const char *key) {
    if (!key || strlen(key) == 0) return;
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->keys[i], key) == 0) return;
    }
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        list->keys = realloc(list->keys, sizeof(char*) * list->capacity);
    }
    list->keys[list->count++] = strdup(key);
}

void free_key_list(KeyList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->keys[i]);
    }
    free(list->keys);
}

void parse_and_add_refs(KeyList *list, const char *refs_str) {
    if (!refs_str || strlen(refs_str) <= 2) return;
    char *copy = strdup(refs_str);
    char *p = copy;
    if (*p == '[') p++;
    size_t len = strlen(p);
    if (len > 0 && p[len-1] == ']') p[len-1] = '\0';
    char *token = strtok(p, ",");
    while (token) {
        while (isspace((unsigned char)*token)) token++;
        char *end = token + strlen(token) - 1;
        while (end > token && isspace((unsigned char)*end)) {
            *end = '\0';
            end--;
        }
        if (strlen(token) > 0) add_unique_key(list, token);
        token = strtok(NULL, ",");
    }
    free(copy);
}

char* smart_escape_regex(const char* pattern) {
    size_t len = strlen(pattern);
    char* result = malloc(len * 2 + 1);
    char* p = result;
    const char* meta = ".*+?()[]{}|^$";
    for (size_t i = 0; i < len; i++) {
        if (pattern[i] == '\\') {
            if (i + 1 < len && (pattern[i+1] == '\\' || strchr(meta, pattern[i+1]))) {
                *p++ = '\\';
                *p++ = pattern[++i];
            } else {
                *p++ = '\\';
                *p++ = '\\';
            }
        } else {
            *p++ = pattern[i];
        }
    }
    *p = '\0';
    return result;
}

void sqlite_regexp(sqlite3_context *context, int argc, sqlite3_value **argv) {
    (void)argc;
    const char *pattern = (const char *)sqlite3_value_text(argv[0]);
    const char *text = (const char *)sqlite3_value_text(argv[1]);
    if (!pattern || !text) {
        sqlite3_result_int(context, 0);
        return;
    }
    regex_t re;
    if (regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB | REG_ICASE) != 0) {
        sqlite3_result_int(context, 0);
        return;
    }
    int ret = regexec(&re, text, 0, NULL, 0);
    regfree(&re);
    sqlite3_result_int(context, ret == 0);
}

void write_latex_header(FILE *out) {
    fprintf(out, "\\documentclass{article}\n");
    fprintf(out, "\\usepackage[utf8]{inputenc}\n");
    fprintf(out, "\\usepackage[ngerman]{babel}\n");
    fprintf(out, "\\usepackage{amsmath, amssymb, amsthm}\n");
    fprintf(out, "\\usepackage{geometry}\n");
    fprintf(out, "\n");
    fprintf(out, "\\usepackage{enumitem}\n");
    fprintf(out, "\\setlist[enumerate]{leftmargin=1cm, itemsep=2pt}\n");
    fprintf(out, "\n");
    fprintf(out, "\\geometry{a4paper, margin=2.5cm}\n");
    fprintf(out, "\\newtheorem{satz}{Satz}[section]\n");
    fprintf(out, "\\newtheorem{axiom}[satz]{Axiom}\n");
    fprintf(out, "\\newtheorem{lemma}[satz]{Lemma}\n");
    fprintf(out, "\\newtheorem{theorem}[satz]{Theorem}\n");
    fprintf(out, "\\theoremstyle{definition}\n");
    fprintf(out, "\\newtheorem{definition}[satz]{Definition}\n");
    fprintf(out, "\\newtheorem{bemerkung}[satz]{Bemerkung}\n");
    fprintf(out, "\\begin{document}\n");
    fprintf(out, "\\title{Wiki Export}\n");
    fprintf(out, "\\author{LLM-Wiki Parser}\n");
    fprintf(out, "\\maketitle\n\n");
}

void write_latex_footer(FILE *out) {
    fprintf(out, "\\end{document}\n");
}

char* latex_ify(const char* input) {
    if (!input) return NULL;
    StringBuilder sb;
    sb_init(&sb, strlen(input) + 128);
    int bold_open = 0;
    
    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] == '*' && input[i+1] == '*') {
            if (!bold_open) {
                sb_append(&sb, "\\textbf{");
                bold_open = 1;
            } else {
                sb_append_char(&sb, '}');
                bold_open = 0;
            }
            i++;
        } else {
            sb_append_char(&sb, input[i]);
        }
    }
    return sb_finish(&sb);
}

void print_available_types(sqlite3 *db) {
    const char *sql = "SELECT DISTINCT type FROM entries ORDER BY type;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, 0) == SQLITE_OK) {
        printf("\nAvailable types in this database:\n");
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const char *type = (const char*)sqlite3_column_text(stmt, 0);
            if (type && strlen(type) > 0) printf("  - %s\n", type);
        }
        sqlite3_finalize(stmt);
    }
}
