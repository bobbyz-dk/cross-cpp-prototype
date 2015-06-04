#pragma once

#include "Publisher.h"
#include "Event.h"
#include "TwitterApi.h"

namespace twitter
{
	using namespace EventHandling;

	public ref class TwitterApiWP sealed
	{
	public:
		TwitterApiWP()
		{
			twitter = new TwitterApi();
			publisher = ref new Publisher();

			publisher->FireEvent +=
				ref new CustomEventHandler(
					this,
					&TwitterApiWP::MyEventHandler);
		}

		void MyEventHandler(Publisher^ mc, size_t nativeClassPtr)
		{
			void *ptr = (void*)nativeClassPtr;
			Event* evnt = (Event*)ptr;
			string tweet;

			switch (evnt->type)
			{
			case Event::EventType::LoadLastTweet:
				tweet = twitter->LoadLastTweet(dynamic_cast<LoadLastTweetEvent*>(evnt)->getScreenName());
				publisher->LastTweetLoaded(tweet);
				break;
			/*case Event::EventType::LastTweetLoaded:
				string str = dynamic_cast<LastTweetLoadedEvent*>(evnt)->getTweet();
				wstring wid_str = wstring(str.begin(), str.end());
				const wchar_t* w_char = wid_str.c_str();
				Platform::String^ p_string = ref new Platform::String(w_char);
				break;*/
			}
		}

	private:
		Publisher^ publisher;
		TwitterApi* twitter;
	};
}