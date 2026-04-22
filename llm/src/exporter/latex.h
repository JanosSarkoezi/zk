#ifndef LATEX_H
#define LATEX_H

#include <stdio.h>
#include <sqlite3.h>
#include "../common/sb_helper.h"

// Structure to manage a unique list of keys
typedef struct {
    char **keys;
    int count;
    int capacity;
} KeyList;

void init_key_list(KeyList *list);
void add_unique_key(KeyList *list, const char *key);
void free_key_list(KeyList *list);
void parse_and_add_refs(KeyList *list, const char *refs_str);

char* smart_escape_regex(const char* pattern);
void sqlite_regexp(sqlite3_context *context, int argc, sqlite3_value **argv);

void write_latex_header(FILE *out);
void write_latex_footer(FILE *out);
char* latex_ify(const char* input);

void print_available_types(sqlite3 *db);

#endif // LATEX_H
