#pragma once
#include <string>

using namespace std;

class Text {
private:
	int id;
	string text;
public:
	Text();
	Text(string _text);
	Text(int _id, string _text);
	~Text();
	int getId();
	string getText();
};

