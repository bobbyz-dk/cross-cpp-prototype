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

	// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
	const std::string currentDateTime() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
		// for more information about date/time format
		strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

		return buf;
	}

	class Comment
	{
	public:
		Comment() {}
		Comment(string text, string email)
		{
			this->text = text;
			this->email = email;
			this->created = currentDateTime();
		}

		string ToString()
		{
			return this->text + " (" + this->created + ")";
		}

		string ToJSON()
		{
			Object comment;

			comment.push_back(Pair("text", this->text));
			comment.push_back(Pair("email", this->email));
			comment.push_back(Pair("created", this->created));
			return write(comment, Output_options::pretty_print, 0);
		}
	private:
		string text;
		string email;
		string created;
	};
}