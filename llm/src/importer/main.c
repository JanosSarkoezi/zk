#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "import.h"
#include "../common/database.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <wiki_dir> <db_path>\n", argv[0]);
        return 1;
    }

    const char *wiki_dir = argv[1];
    const char *db_path = argv[2];

    sqlite3 *db = init_db(db_path);
    if (!db) return 1;

    DIR *dir = opendir(wiki_dir);
    if (!dir) {
        perror("Could not open wiki directory");
        close_db(db);
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Only process .md files
        if (strstr(entry->d_name, ".md") != NULL) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", wiki_dir, entry->d_name);

            Document doc = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
            printf("Parsing %s...\n", entry->d_name);
            parse_file(full_path, &doc);
            
            if (doc.key) {
                save_to_db(&doc, db);
            }
            
            free_document(&doc);
        }
    }

    closedir(dir);
    close_db(db);

    printf("Ingest completed.\n");
    return 0;
}
