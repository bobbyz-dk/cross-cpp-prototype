#include "TextDao.h"
#include <sstream>

TextDao::TextDao(string dbPath)
{
	char *cstr = new char[dbPath.length() + 1];
	db = new DBManager(strcpy(cstr, dbPath.c_str()));
}

TextDao::~TextDao()
{
	if (db != NULL)
		db->~DBManager();
}

void TextDao::insert(Text *text)
{
	string query = "INSERT INTO Text(text) VALUES('" + text->getText() + "');";
	char *cstr = new char[query.length() + 1];
	if (db->open("TextDB.db"))
	{
		db->query(strcpy(cstr, query.c_str()));
	}
	db->close();
}

vector<Text*> TextDao::findAll()
{
	vector<Text*> texts(0);
	char *query = "SELECT * FROM Text;";
	if (db->open("TextDB.db"))
	{
		vector<vector<string>> result = db->query(query);
		for (vector<vector<string>>::iterator it = result.begin(); it < result.end(); ++it)
		{
			vector<string> row = *it;
			int id;
			istringstream idString(row.at(0));
			idString >> id;
			texts.emplace(texts.end(), new Text(id, row.at(1)));
		}
	}
	db->close();
	return texts;
}