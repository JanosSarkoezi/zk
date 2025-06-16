#include "import.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// --- StringBuilder Helper ---
typedef struct {
    char *buffer;
    size_t length;
    size_t capacity;
} StringBuilder;

static void sb_init(StringBuilder *sb) {
    sb->capacity = 1024;
    sb->length = 0;
    sb->buffer = malloc(sb->capacity);
    if (sb->buffer) sb->buffer[0] = '\0';
}

static void sb_append(StringBuilder *sb, const char *str) {
    if (!str) return;
    size_t len = strlen(str);
    if (sb->length + len + 1 > sb->capacity) {
        // Exponential growth
        while (sb->length + len + 1 > sb->capacity) {
            sb->capacity *= 2;
        }
        char *temp = realloc(sb->buffer, sb->capacity);
        if (temp) {
            sb->buffer = temp;
        } else {
            return; // In a real app, handle out-of-memory
        }
    }
    memcpy(sb->buffer + sb->length, str, len + 1);
    sb->length += len;
}

static char* sb_finish(StringBuilder *sb) {
    char *final = sb->buffer;
    // Shrink to fit (optional, but good for long-term storage in Document)
    char *shrunk = realloc(final, sb->length + 1);
    return shrunk ? shrunk : final;
}

// --- Original Helper for Metadata (YAML) ---
void append_string(char **destination, const char *source) {
    if (source == NULL) return;

    if (*destination == NULL) {
        *destination = malloc(strlen(source) + 1);
        if (*destination) {
            strcpy(*destination, source);
        }
    } else {
        size_t new_size = strlen(*destination) + strlen(source) + 1;
        char *temp = realloc(*destination, new_size);
        if (temp) {
            *destination = temp;
            strcat(*destination, source);
        }
    }
}

static char* trim_whitespace(char *str) {
    char *end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

static void extract_yaml_value(char *line, Document *doc) {
    char *colon = strchr(line, ':');
    if (!colon) return;

    *colon = '\0';
    char *key = trim_whitespace(line);
    char *value = trim_whitespace(colon + 1);

    if (strcmp(key, "key") == 0) append_string(&doc->key, value);
    else if (strcmp(key, "title") == 0) append_string(&doc->title, value);
    else if (strcmp(key, "type") == 0) append_string(&doc->type, value);
    else if (strcmp(key, "tags") == 0) append_string(&doc->tags, value);
    else if (strcmp(key, "refs") == 0) append_string(&doc->refs, value);
}

void parse_file(const char *filename, Document *doc) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    StringBuilder content_sb, proof_sb;
    sb_init(&content_sb);
    sb_init(&proof_sb);

    char line[4096];
    int state = 0; // 0: Searching for Header, 1: Inside Header, 2: Inside Content, 3: Inside Proof

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "---", 3) == 0) {
            if (state == 0) state = 1;
            else if (state == 1) state = 2;
            continue;
        }

        if (strncmp(line, "--proof--", 9) == 0) {
            state = 3;
            continue;
        }

        switch (state) {
            case 1:
                extract_yaml_value(line, doc);
                break;
            case 2:
                sb_append(&content_sb, line);
                break;
            case 3:
                sb_append(&proof_sb, line);
                break;
        }
    }
    
    doc->content = sb_finish(&content_sb);
    doc->proof = sb_finish(&proof_sb);
    
    fclose(file);
}

void free_document(Document *doc) {
    free(doc->key);
    free(doc->title);
    free(doc->type);
    free(doc->tags);
    free(doc->refs);
    free(doc->content);
    free(doc->proof);
    
    doc->key = doc->title = doc->type = doc->tags = doc->refs = doc->content = doc->proof = NULL;
}
