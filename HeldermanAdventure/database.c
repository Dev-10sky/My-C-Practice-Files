#include <stdio.h>
#include <sqlite3.h>
#include "database.h"


static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

static void closeDB(sqlite3 *db, const char *dbName)
{
	sqlite3_close(db);
	printf("Database %s has been closed.\n", dbName);
}

sqlite3 *openDB(sqlite3 *db,const char *dbName)
{

	int ret_c;
	ret_c = sqlite3_open(dbName, &db);

	if (ret_c)
	{
		fprintf(stderr, "Database opening failed, error: %s\n", sqlite3_errmsg(db));
		return NULL;
	}
	else
	{
		fprintf(stdout, "Database opening success!\n");
	}
	return db;
}

int createDbTable(sqlite3 *db, const char *createQuery, const char *tableName, const char *dbName)
{
	int ret_c;
	char *zErrMsg = 0;
	ret_c = sqlite3_exec(db, createQuery, NULL, NULL, &zErrMsg);
	printf("Trying query: %s \n",createQuery);
	if (ret_c != SQLITE_OK)
	{
		fprintf(stdout, "Table %s creation failed, SQL error: %s.\n", tableName,zErrMsg);
		sqlite3_free(zErrMsg);
		return 1;
	}
	else
	{
		fprintf(stdout, "Table %s creation success!\n",tableName);
	}
	return 0;
}




int main(int argc, char* argv[])
{
	sqlite3 *db;
	const char name[] = "test.db";
	sqlite3 *chk = openDB(db, name);

	const char tbName[] = "GAMEOBJECTS";

	const char *query = "CREATE TABLE IF NOT EXISTS GAMEOBJECTS ("
      		"ID INTEGER PRIMARY KEY NOT NULL,"
      		"DESCRIPTION TEXT NOT NULL,"
      		"TAGS TEXT,"
     		"LOCATION_ID INTEGER,"
     		"DESTINATION_ID INTEGER,"
     		"PROSPECT_ID INTEGER,"
      		"DETAILS TEXT,"
      		"CONTENTS TEXT,"
      		"TEXTGO TEXT,"
      		"GOSSIP TEXT,"
     		"WEIGHT INTEGER,"
     		"CAPACITY INTEGER,"
     		"HEALTH INTEGER,"
     		"LIGHT INTEGER,"
     		"IMPACT INTEGER,"
     		"TRUST INTEGER);";
	int r_chk = createDbTable(chk, query, tbName, name);
	closeDB(chk, name);
	return 0;
}
