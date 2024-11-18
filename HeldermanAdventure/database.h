#ifndef DATABASE_H
#define DATABASE_H

extern sqlite3 *openDB(sqlite3 *db,const char *dbName);
extern int createDbTable(sqlite3 *db, const char *createQuery, const char *tableName, const char *dbName);

#endif
