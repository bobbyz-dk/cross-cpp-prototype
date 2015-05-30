#include "TextDao.h"
#include <sstream>
#include "log.h"

TextDao::TextDao(string dbPath)
{
	char *cstr = new char[dbPath.length() + 1];
	db = new DBManager(strcpy(cstr, dbPath.c_str()));
	this->dbPath = dbPath;
}

TextDao::~TextDao()
{
	if (db != NULL)
		db->~DBManager();
}

void TextDao::insert(Text *text)
{
	//logdebug("TextDao", strcat("insert_begin - dbPath:", dbPath.c_str()));
	if (db == NULL)
	{
		logdebug("TextDao", "insert_db_1");
		char *cstr = new char[dbPath.length() + 1];
		logdebug("TextDao", "insert_db_2");
		db = new DBManager(strcpy(cstr, dbPath.c_str()));
		logdebug("TextDao", "insert_db_3");
	}
	string query = "INSERT INTO Text(text) VALUES('" + text->getText() + "');";
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
	char *query = "SELECT * FROM Text;"; // fix string to char*
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