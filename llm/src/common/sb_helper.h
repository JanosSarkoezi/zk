#ifndef SB_HELPER_H
#define SB_HELPER_H

#include <stddef.h>

typedef struct {
    char *buffer;
    size_t length;
    size_t capacity;
} StringBuilder;

void sb_init(StringBuilder *sb, size_t initial_cap);
void sb_append(StringBuilder *sb, const char *str);
void sb_append_char(StringBuilder *sb, char c);
char* sb_finish(StringBuilder *sb);
void sb_free(StringBuilder *sb);

#endif // SB_HELPER_H
