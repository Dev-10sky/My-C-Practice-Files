#ifndef DATABASE_H
#define DATABASE_H

extern sqlite3 *openDB(sqlite3 *db,const char *dbName);
extern int createDbTable(sqlite3 *db, const char *createQuery, const char *tableName, const char *dbName);
extern int insertDbTable(sqlite3 *db, const char *insrtQuery, const char *tableName, const char *dbName);
extern int viewDbTable(sqlite3 *db, const char *viewQuery, const char *tableName, const char *dbName);
extern int retrieveDbTable(sqlite3 *db, const char *getQuery, const char *tableName, const char *dbName);

#endif
