#include "database.h"
#include <stdio.h>
#include <stdlib.h>

sqlite3* init_db(const char *db_name) {
    sqlite3 *db;
    int rc = sqlite3_open(db_name, &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return NULL;
    }

    const char *sql = "CREATE TABLE IF NOT EXISTS entries ("
                      "key TEXT PRIMARY KEY,"
                      "title TEXT,"
                      "type TEXT,"
                      "tags TEXT,"
                      "refs TEXT,"
                      "content TEXT,"
                      "proof TEXT"
                      ");";

    char *zErrMsg = 0;
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return db;
}

void save_to_db(Document *doc, sqlite3 *db) {
    if (!doc->key) return;

    const char *sql = "INSERT INTO entries (key, title, type, tags, refs, content, proof) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?) "
                      "ON CONFLICT(key) DO UPDATE SET "
                      "title=excluded.title, "
                      "type=excluded.type, "
                      "tags=excluded.tags, "
                      "refs=excluded.refs, "
                      "content=excluded.content, "
                      "proof=excluded.proof;";
    sqlite3_stmt *stmt;

    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, doc->key, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, doc->title, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, doc->type, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, doc->tags, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, doc->refs, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, doc->content, -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, doc->proof, -1, SQLITE_TRANSIENT);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void close_db(sqlite3 *db) {
    sqlite3_close(db);
}
