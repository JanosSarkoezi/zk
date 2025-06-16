#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sqlite3.h>
#include <regex.h>

// --- StringBuilder for general use ---
typedef struct {
    char *buffer;
    size_t length;
    size_t capacity;
} StringBuilder;

void sb_init(StringBuilder *sb, size_t initial_cap) {
    sb->capacity = initial_cap > 0 ? initial_cap : 1024;
    sb->length = 0;
    sb->buffer = malloc(sb->capacity);
    if (sb->buffer) sb->buffer[0] = '\0';
}

void sb_append(StringBuilder *sb, const char *str) {
    if (!str) return;
    size_t len = strlen(str);
    if (sb->length + len + 1 > sb->capacity) {
        while (sb->length + len + 1 > sb->capacity) {
            sb->capacity *= 2;
        }
        char *temp = realloc(sb->buffer, sb->capacity);
        if (temp) sb->buffer = temp;
    }
    memcpy(sb->buffer + sb->length, str, len + 1);
    sb->length += len;
}

void sb_append_char(StringBuilder *sb, char c) {
    if (sb->length + 2 > sb->capacity) {
        sb->capacity *= 2;
        char *temp = realloc(sb->buffer, sb->capacity);
        if (temp) sb->buffer = temp;
    }
    sb->buffer[sb->length++] = c;
    sb->buffer[sb->length] = '\0';
}

char* sb_finish(StringBuilder *sb) {
    return sb->buffer; // Final string, needs to be freed by caller
}

void sb_free(StringBuilder *sb) {
    free(sb->buffer);
    sb->buffer = NULL;
}

// Structure to manage a unique list of keys
typedef struct {
    char **keys;
    int count;
    int capacity;
} KeyList;

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

static void sqlite_regexp(sqlite3_context *context, int argc, sqlite3_value **argv) {
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

int main(int argc, char *argv[]) {
    if (argc < 3 || (argc == 2 && strcmp(argv[1], "--help") == 0)) {
        printf("Usage: %s <db_path> <output_tex> [--refs] [--type <category>] <keywords...>\n\n", argv[0]);
        if (argc >= 2) {
            sqlite3 *db;
            if (sqlite3_open(argv[1], &db) == SQLITE_OK) {
                print_available_types(db);
                sqlite3_close(db);
            }
        }
        return (argc < 3) ? 1 : 0;
    }

    const char *db_path = argv[1];
    const char *out_path = argv[2];
    const char *type_filter = NULL;
    int include_refs = 0;
    int start_idx = 3;

    while (start_idx < argc && argv[start_idx][0] == '-') {
        if (strcmp(argv[start_idx], "--refs") == 0) {
            include_refs = 1;
            start_idx++;
        } else if (strcmp(argv[start_idx], "--type") == 0 && start_idx + 1 < argc) {
            type_filter = argv[start_idx + 1];
            start_idx += 2;
        } else break;
    }

    sqlite3 *db;
    if (sqlite3_open(db_path, &db) != SQLITE_OK) return 1;
    sqlite3_create_function(db, "REGEXP", 2, SQLITE_UTF8, NULL, sqlite_regexp, NULL, NULL);

    KeyList export_keys;
    init_key_list(&export_keys);

    StringBuilder sql_sb;
    sb_init(&sql_sb, 1024);
    sb_append(&sql_sb, "SELECT key, refs FROM entries WHERE ");
    int first_search_part = 1;

    if (type_filter) {
        char *temp = sqlite3_mprintf("(type = '%q') ", type_filter);
        sb_append(&sql_sb, temp);
        sqlite3_free(temp);
        first_search_part = 0;
    }

    for (int i = start_idx; i < argc; i++) {
        char *escaped = smart_escape_regex(argv[i]);
        char *part = sqlite3_mprintf("%s(key REGEXP '%q' OR title REGEXP '%q' OR tags REGEXP '%q' OR content REGEXP '%q' OR proof REGEXP '%q')", 
                                     (!first_search_part ? " AND " : ""), escaped, escaped, escaped, escaped, escaped);
        sb_append(&sql_sb, part);
        sqlite3_free(part);
        free(escaped);
        first_search_part = 0;
    }

    if (start_idx == argc && !type_filter) {
        sb_free(&sql_sb);
        sb_init(&sql_sb, 64);
        sb_append(&sql_sb, "SELECT key, refs FROM entries");
    }

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sb_finish(&sql_sb), -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const char *key = (const char*)sqlite3_column_text(stmt, 0);
            const char *refs = (const char*)sqlite3_column_text(stmt, 1);
            add_unique_key(&export_keys, key);
            if (include_refs) parse_and_add_refs(&export_keys, refs);
        }
        sqlite3_finalize(stmt);
    }
    sb_free(&sql_sb);

    if (export_keys.count == 0) {
        printf("No entries found.\n");
        print_available_types(db);
        free_key_list(&export_keys);
        sqlite3_close(db);
        return 0;
    }

    FILE *out = fopen(out_path, "w");
    if (!out) {
        free_key_list(&export_keys);
        sqlite3_close(db);
        return 1;
    }

    write_latex_header(out);

    StringBuilder in_sb;
    sb_init(&in_sb, export_keys.count * 16);
    for (int i = 0; i < export_keys.count; i++) {
        char *temp = sqlite3_mprintf("%s'%q'", (i > 0 ? "," : ""), export_keys.keys[i]);
        sb_append(&in_sb, temp);
        sqlite3_free(temp);
    }

    char *final_sql = sqlite3_mprintf(
        "SELECT key, title, type, content, proof FROM entries WHERE key IN (%s) "
        "ORDER BY CASE type "
        "  WHEN 'axiom' THEN 1 WHEN 'definition' THEN 2 WHEN 'def' THEN 2 "
        "  WHEN 'satz' THEN 3 WHEN 'theorem' THEN 3 WHEN 'lemma' THEN 3 "
        "  ELSE 4 END, title ASC", sb_finish(&in_sb));
    sb_free(&in_sb);

    if (sqlite3_prepare_v2(db, final_sql, -1, &stmt, 0) == SQLITE_OK) {
        int count = 0;
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const char *key = (const char*)sqlite3_column_text(stmt, 0);
            const char *title = (const char*)sqlite3_column_text(stmt, 1);
            const char *type = (const char*)sqlite3_column_text(stmt, 2);
            const char *content = (const char*)sqlite3_column_text(stmt, 3);
            const char *proof = (const char*)sqlite3_column_text(stmt, 4);

            char env[32] = "theorem";
            if (type) {
                if (strcmp(type, "satz") == 0) strcpy(env, "satz");
                else if (strcmp(type, "axiom") == 0) strcpy(env, "axiom");
                else if (strcmp(type, "def") == 0 || strcmp(type, "definition") == 0) strcpy(env, "definition");
                else if (strcmp(type, "lemma") == 0) strcpy(env, "lemma");
                else if (strcmp(type, "bemerkung") == 0) strcpy(env, "bemerkung");
            }

            fprintf(out, "%% --- %s ---\n\\begin{%s}[%s]\n", key, env, title ? title : key);
            char *latex_content = latex_ify(content);
            fprintf(out, "%s\n\\end{%s}\n", latex_content ? latex_content : "", env);
            free(latex_content);

            if (proof && strlen(proof) > 0) {
                char *latex_proof = latex_ify(proof);
                fprintf(out, "\\begin{proof}\n%s\\end{proof}\n", latex_proof);
                free(latex_proof);
            }
            count++;
        }
        sqlite3_finalize(stmt);
        printf("Exported %d entries %s to %s\n", count, include_refs ? "(including dependencies)" : "", out_path);
    }
    write_latex_footer(out);
    sqlite3_free(final_sql);
    fclose(out);
    free_key_list(&export_keys);
    sqlite3_close(db);
    return 0;
}
