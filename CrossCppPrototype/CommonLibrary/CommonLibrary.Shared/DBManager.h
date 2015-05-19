#pragma once
#ifndef __DBMANAGER_H__
#define __DBMANAGER_H__

#include <string>
#include <vector>
#include <sqlite3.h>

using namespace std;

class DBManager
{
public:
	DBManager(char* filename);
	~DBManager();

	bool open(char* filename);
	vector<vector<string>> query(char* query);
	void close();

private:
	sqlite3 *database;
};

#endif