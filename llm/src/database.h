#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include "document.h"

sqlite3* init_db(const char *db_name);
void save_to_db(Document *doc, sqlite3 *db);
void close_db(sqlite3 *db);

#endif // DATABASE_H
