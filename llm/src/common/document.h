#ifndef DOCUMENT_H
#define DOCUMENT_H

typedef struct {
    char *key;
    char *title;
    char *type;
    char *tags;  // Kommagetrennter String
    char *refs;  // Kommagetrennter String
    char *content;
    char *proof;
} Document;

#endif // DOCUMENT_H
