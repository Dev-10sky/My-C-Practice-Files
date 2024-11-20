#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include "database.h"


static int callback(void *data, int argc, char **argv, char **azColName)
{
	printf("%s: ", (const char*)data);
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
	printf("\nDatabase %s has been closed.\n", dbName);
}

sqlite3 *openDB(sqlite3 *db,const char *dbName)
{

	int ret_c;
	ret_c = sqlite3_open(dbName, &db);

	if (ret_c)
	{
		fprintf(stderr, "\nDatabase opening failed, error: %s\n", sqlite3_errmsg(db));
		return NULL;
	}
	else
	{
		fprintf(stdout, "\nDatabase opening success!\n");
	}
	return db;
}

int createDbTable(sqlite3 *db, const char *createQuery, const char *tableName, const char *dbName)
{
	int ret_c;
	char *zErrMsg = 0;
	ret_c = sqlite3_exec(db, createQuery, callback, 0, &zErrMsg);
	printf("\nTrying query:\n %s \n",createQuery);
	if (ret_c != SQLITE_OK)
	{
		fprintf(stdout, "Table %s creation failed, SQL error: %s.\n", tableName,zErrMsg);
		sqlite3_free(zErrMsg);
		return 1;
	}
	else
	{
		fprintf(stdout, "\nTable %s creation success!\n",tableName);
	}
	return 0;
}

int insertDbTable(sqlite3 *db, const char *insrtQuery, const char *tableName, const char *dbName)
{
	int ret_c;
	char *zErrMsg = 0;

	ret_c = sqlite3_exec(db, insrtQuery, callback, 0, &zErrMsg);
	printf("\nTrying query:\n %s \n",insrtQuery);

	if (ret_c != SQLITE_OK)
	{
		fprintf(stdout, "Table %s insertion failed, SQL error: %s.\n", tableName,zErrMsg);
		sqlite3_free(zErrMsg);
		return 1;
	}
	else
	{
		fprintf(stdout, "\nTable %s insertion success!\n",tableName);
	}
	return 0;
}

int viewDbTable(sqlite3 *db, const char *viewQuery, const char *tableName, const char *dbName)
{
	int ret_c;
	char *zErrMsg = 0;
	const char* data = "Callback function called";

	ret_c = sqlite3_exec(db, viewQuery, callback, (void*)data, &zErrMsg);
	printf("\nTrying query:\n %s \n",viewQuery);

	if (ret_c != SQLITE_OK)
	{
		fprintf(stdout, "Table %s selection failed, SQL error: %s.\n", tableName,zErrMsg);
		sqlite3_free(zErrMsg);
		return 1;
	}
	else
	{
		fprintf(stdout, "\nTable %s selection success!\n",tableName);
	}
	return 0;
}

int retrieveDbTable(sqlite3 *db, const char *getQuery, const char *tableName, const char *dbName)
{
	int ret_c;
	const char *zErrMsg;
	const char* data = "Callback function called";
	sqlite3_stmt* ret_statement;
	size_t sql_len = strlen(getQuery);

	ret_c = sqlite3_prepare_v2(db, getQuery, sql_len,&ret_statement,&zErrMsg);
	printf("\nTrying query:\n %s \n",getQuery);

	int row_counter = 0;

	if (ret_c == SQLITE_OK)
	{
		fprintf(stdout, "\nTable %s retrieval success!\n",tableName);
		fprintf(stdout,"(ID, Name, Condition, Description, Tags)\n");
		while (sqlite3_step(ret_statement) == SQLITE_ROW)
		{
			printf("%d | %s | %s | %s | %s\n",
				sqlite3_column_int(ret_statement, 0),
				sqlite3_column_text(ret_statement, 1),
				sqlite3_column_text(ret_statement, 2),
				sqlite3_column_text(ret_statement, 3),
				sqlite3_column_text(ret_statement, 4)
				);
		}
	}
	else
	{
		const char* db_error_msg = sqlite3_errmsg(db);
		fprintf(stdout, "Table %s retrieval failed, SQL error: %s.\n", tableName,db_error_msg);
	}

	sqlite3_finalize(ret_statement);
	return 0;
}




int main(int argc, char* argv[])
{
	sqlite3 *db;
	const char name[] = "test.db";
	sqlite3 *chk = openDB(db, name);

	const char tbName[] = "GAMEOBJECTS";

	const char *setupQuery = "CREATE TABLE IF NOT EXISTS GAMEOBJECTS ("
      		"ID INTEGER PRIMARY KEY NOT NULL,"
      		"NAME TEXT NOT NULL,"
      		"CONDITION TEXT,"
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
     		"TRUST INTEGER,"
		"OPEN_FUNCTION TEXT,"
		"CLOSE_FUNCTION TEXT,"
		"LOCK_FUNCTION TEXT,"
		"UNLOCK_FUNCTION TEXT"
		");";
/*
		"INSERT INTO GAMEOBJECTS ("
      		"ID, NAME, CONDITION, DESCRIPTION, TAGS, LOCATION_ID, DESTINATION_ID, PROSPECT_ID,"
      		"DETAILS, CONTENTS, TEXTGO, GOSSIP, WEIGHT, CAPACITY, HEALTH, LIGHT, IMPACT, TRUST,"
		"OPEN_FUNCTION, CLOSE_FUNCTION, LOCK_FUNCTION, UNLOCK_FUNCTION"
		") "
		"VALUES (1,'','','','', , , ,'','','','', , , , , , ,'','','','');"
*/
	const char *insertQuery = "INSERT INTO GAMEOBJECTS ("
      		"ID, NAME, CONDITION, DESCRIPTION, TAGS, LOCATION_ID, DESTINATION_ID, PROSPECT_ID,"
      		"DETAILS, CONTENTS, TEXTGO, GOSSIP, WEIGHT, CAPACITY, HEALTH, LIGHT, IMPACT, TRUST,"
		"OPEN_FUNCTION, CLOSE_FUNCTION, LOCK_FUNCTION, UNLOCK_FUNCTION) "
		"VALUES (1,'heaven','alwaysTrue','little heaven','heaven, little heaven, NULL',"
		"null ,null ,null ,'Everything looks so peaceful here.','You see',"
		"'You cant get much closer than this.','Its where all the good adventurers go.',"
		"99,9999,0,100,0,0,'cannotBeOpened','cannotBeClosed','cannotBeLocked','cannotBeUnlocked');";

	const char *selectQuery = "SELECT * FROM GAMEOBJECTS";

	// Table Creation
	int r_chk = createDbTable(chk, setupQuery, tbName, name);
	closeDB(chk, name);

	// Table Insertion
	chk = openDB(db, name);
	r_chk = insertDbTable(chk, insertQuery, tbName, name);
	closeDB(chk, name);

	// Table Selection
	chk = openDB(db, name);
	r_chk = viewDbTable(chk, selectQuery, tbName, name);
	closeDB(chk, name);

	// Table Retrieval
	chk = openDB(db, name);
	r_chk = retrieveDbTable(chk, selectQuery, tbName, name);
	closeDB(chk, name);

	return 0;
}
