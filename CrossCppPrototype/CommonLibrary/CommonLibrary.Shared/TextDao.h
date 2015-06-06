#pragma once

#include <string>
#include <vector>
#include "sqlite/sqlite3.h"
#include "DBManager.h"
#include "Text.h"

using namespace std;

class TextDao
{
public:
	TextDao(string dbPath);
	~TextDao();
	void insert(Text *text);
	vector<Text*> findAll();

private:
	DBManager *db;
	string dbPath;
};