#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "latex.h"
#include "../common/sb_helper.h"

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
    char *search_sql = sb_finish(&sql_sb);
    if (sqlite3_prepare_v2(db, search_sql, -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const char *key = (const char*)sqlite3_column_text(stmt, 0);
            const char *refs = (const char*)sqlite3_column_text(stmt, 1);
            add_unique_key(&export_keys, key);
            if (include_refs) parse_and_add_refs(&export_keys, refs);
        }
        sqlite3_finalize(stmt);
    }
    // Note: search_sql points to internal buffer of sql_sb, but sb_finish returns it.
    // However, our sb_finish doesn't null the buffer, so sb_free would free it.
    // Let's be careful. In my sb_helper.c, sb_finish just returns the buffer.
    // So sb_free must be called AFTER we are done with search_sql.
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
