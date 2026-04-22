#ifndef IMPORT_H
#define IMPORT_H

#include "../common/document.h"

void parse_file(const char *filename, Document *doc);
void free_document(Document *doc);
void append_string(char **destination, const char *source);

#endif // IMPORT_H
