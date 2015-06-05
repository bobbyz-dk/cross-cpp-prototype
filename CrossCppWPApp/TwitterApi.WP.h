#pragma once

#include "TwitterApi.h"

namespace twitter
{

	class TwitterApiWP
	{
	public:
		TwitterApiWP()
		{
			twitter = new TwitterApi();
		}
		
		string LoadLastTweet(string screenName)
		{
			return twitter->LoadLastTweet(screenName);
		}


	private:
		TwitterApi* twitter;
	};
}