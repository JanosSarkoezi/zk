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
        size_t len = strlen(entry->d_name);
        // Prüfen, ob der Dateiname lang genug ist und exakt auf ".md" endet
        if (len > 3 && strcmp(entry->d_name + len - 3, ".md") == 0) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", wiki_dir, entry->d_name);

            Document doc = {NULL, NULL, NULL, NULL, NULL, NULL, NULL};
            printf("Parsing %s...\n", entry->d_name);
            parse_file(full_path, &doc);

            // Nur speichern, wenn auch wirklich ein Key ausgelesen werden konnte
            if (doc.key) {
                save_to_db(&doc, db);
            } else {
                fprintf(stderr, "Warning: Skipping %s (no valid 'key' found in YAML header)\n", entry->d_name);
            }

            free_document(&doc);
        }
    }

    closedir(dir);
    close_db(db);

    printf("Ingest completed.\n");
    return 0;
}
