#include "TextDao.h"
#include <sstream>
#include "log.h"

TextDao::TextDao(string dbPath)
{
	logdebug("TextDao", "constr_1");
	char *cstr = new char[dbPath.length() + 1];
	logdebug("TextDao", "constr_2");
	db = new DBManager(strcpy(cstr, dbPath.c_str()));
	logdebug("TextDao", "constr_3");
	this->dbPath = dbPath;
	logdebug("TextDao", "constr_4");
	createTable();
	logdebug("TextDao", "constr_5");
}

TextDao::~TextDao()
{
	if (db != 0)
		db->~DBManager();
}

void TextDao::insert(Text *text)
{
	//logdebug("TextDao", strcat("insert_begin - dbPath:", dbPath.c_str()));
	logdebug("TextDao", "insert_begin");
	logdebug("TextDao", db->getDbPath());
	if (db == 0)
	{
		logdebug("TextDao", "insert_db_1");
		char *cstr = new char[dbPath.length() + 1];
		logdebug("TextDao", "insert_db_2");
		db = new DBManager(strcpy(cstr, dbPath.c_str()));
		logdebug("TextDao", "insert_db_3");
	}
	logdebug("TextDao", "insert_0");
	string query = "INSERT INTO text(text) VALUES('" + text->getText() + "');";
	logdebug("TextDao", "insert_1");
	char *cstr = new char[query.length() + 1];
	logdebug("TextDao", "insert_2 - db:");
	if (db->open(db->getDbPath()))
	{
		logdebug("TextDao", "insert_3");
		db->query(strcpy(cstr, query.c_str()));
		logdebug("TextDao", "insert_4");
	}
	logdebug("TextDao", "insert_5");
	db->close();
	logdebug("TextDao", "insert_end");
}

vector<Text*> TextDao::findAll()
{
	vector<Text*> texts;
	char *query = "SELECT * FROM text;"; // fix string to char*
	if (db->open(db->getDbPath()))
	{
		vector<vector<string> > result = db->query(query);
		for (vector<vector<string> >::iterator it = result.begin(); it < result.end(); ++it)
		{
			vector<string> row = *it;
			int id;
			istringstream idString(row.at(0));
			idString >> id;
			texts.push_back(new Text(id, row.at(1)));
		}
	}
	db->close();
	return texts;
}

void TextDao::createTable()
{
	//logdebug("TextDao", strcat("createTable_begin - dbPath:", dbPath.c_str()));
	logdebug("TextDao", "createTable_begin");
	if (db == 0)
	{
		logdebug("TextDao", "createTable_1");
		char *cstr = new char[dbPath.length() + 1];
		db = new DBManager(strcpy(cstr, dbPath.c_str()));
		logdebug("TextDao", "createTable_2");
	}
	logdebug("TextDao", "createTable_2.5");
	string query = "CREATE TABLE text (id integer, text text, PRIMARY KEY(id));";
	char *cstr = new char[query.length() + 1];
	logdebug("TextDao", "createTable_3");
	if (db->open(db->getDbPath()))
	{
		logdebug("TextDao", "createTable_4");
		db->query(strcpy(cstr, query.c_str()));
		logdebug("TextDao", "createTable_5");
	}
	logdebug("TextDao", "createTable_6");
	db->close();
	logdebug("TextDao", "createTable_7");
}