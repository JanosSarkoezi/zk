#include "sb_helper.h"
#include <stdlib.h>
#include <string.h>

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
    return sb->buffer;
}

void sb_free(StringBuilder *sb) {
    free(sb->buffer);
    sb->buffer = NULL;
}
