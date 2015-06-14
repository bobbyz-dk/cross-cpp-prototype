#include <stdio.h>
#include <string>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "twitcurl.h"

namespace twitter
{
	using namespace std;

	class TwitterApi {

	public:
		TwitterApi();
		~TwitterApi();

		string LoadLastTweet(string screenName);
	};
}