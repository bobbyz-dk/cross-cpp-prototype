#include "DBManager.h"
#include <string>
#include <android/log.h>

#define LOGD(TAG,...) __android_log_print(ANDROID_LOG_DEBUG  , TAG,__VA_ARGS__)

DBManager::DBManager(char * filename)
{
	LOGD("DBManager", "DBManager1_1");
	database = NULL;
	LOGD("DBManager", "DBManager1_2");
	dbPath = filename;
	LOGD("DBManager", "DBManager1_3");
	open(getDbPath());
	LOGD("DBManager", "DBManager1_4");
	close();
	LOGD("DBManager", "DBManager1_5");
}

DBManager::~DBManager()
{}

char * DBManager::getDbPath()
{
	//LOGD("DBManager", strcat("getDbPath", dbPath));
	return dbPath;
}

bool DBManager::open(char* filename)
{
	LOGD("DBManager", "open1");
	if (sqlite3_open(filename, &database) == SQLITE_OK)
		return true;
	LOGD("DBManager", "open2");
	return false;
}

vector<vector<string> > DBManager::query(char* query)
{
	sqlite3_stmt *statement;
	vector<vector<string> > results;

	if (sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while (true)
		{
			result = sqlite3_step(statement);

			if (result == SQLITE_ROW)
			{
				vector<string> values;
				for (int col = 0; col < cols; col++)
				{
					values.push_back((char*)sqlite3_column_text(statement, col));
				}
				results.push_back(values);
			}
			else
			{
				break;
			}
		}
		sqlite3_finalize(statement);
	}

	string error = sqlite3_errmsg(database);
	if (error != "not an error")
	{
		printf("%s: %s", query, error.c_str());
	}
	return results;
}

void DBManager::close()
{
	sqlite3_close(database);
}