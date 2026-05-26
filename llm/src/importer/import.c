#include "import.h"
#include "../common/sb_helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Ersetzt oder initialisiert einen String-Pointer sicher
void assign_string(char **destination, const char *source) {
    if (!source) return;
    if (*destination) {
        free(*destination); // Alten Wert freigeben, falls vorhanden
    }
    *destination = strdup(source);
}

static char* trim_whitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

static void extract_yaml_value(char *line, Document *doc) {
    char *colon = strchr(line, ':');
    if (!colon) return;

    *colon = '\0';
    char *key = trim_whitespace(line);
    char *value = trim_whitespace(colon + 1);

    if (strcmp(key, "key") == 0) assign_string(&doc->key, value);
    else if (strcmp(key, "title") == 0) assign_string(&doc->title, value);
    else if (strcmp(key, "type") == 0) assign_string(&doc->type, value);
    else if (strcmp(key, "tags") == 0) assign_string(&doc->tags, value);
    else if (strcmp(key, "refs") == 0) assign_string(&doc->refs, value);
}

void parse_file(const char *filename, Document *doc) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    StringBuilder content_sb, proof_sb;
    sb_init(&content_sb, 512);
    sb_init(&proof_sb, 128);

    char line[4096];
    int state = 0; // 0: Searching for Header, 1: Inside Header, 2: Inside Content, 3: Inside Proof

    while (fgets(line, sizeof(line), file)) {
        // YAML-Begrenzer erkennen
        if (strncmp(line, "---", 3) == 0) {
            if (state == 0) {
                state = 1;
            } else if (state == 1) {
                state = 2;
            }
            continue;
        }

        // Sektions-Wechsel erkennen
        if (state >= 2) {
            if (strncmp(line, "--proof--", 9) == 0 || strncmp(line, "--examples--", 12) == 0) {
                state = 3;
                continue;
            }
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

    // Die Buffer an das Dokument übergeben
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
