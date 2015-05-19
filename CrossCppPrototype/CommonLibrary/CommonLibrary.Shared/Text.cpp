#include "Text.h"

Text::Text()
{
}

Text::Text(string _text)
{
	this->text = _text;
}

Text::Text(int _id, string _text)
{
	this->id = _id;
	this->text = _text;
}

Text::~Text()
{}

int Text::getId()
{
	return id;
}

string Text::getText()
{
	return text;
}