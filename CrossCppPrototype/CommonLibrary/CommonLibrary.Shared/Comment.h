#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "json_spirit.h"

namespace model
{
	using namespace std;
	using namespace json_spirit;

	class Comment
	{
	public:
		Comment();
		Comment(string text, string email);
		string ToString();
		string ToJSON();
	private:
		string text;
		string email;
		string created;
	};
}