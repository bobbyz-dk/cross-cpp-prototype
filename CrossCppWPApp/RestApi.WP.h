#pragma once
#include "Event.h"
#include "Publisher.h"
#include "RestApi.h"

namespace RestApiSpace
{
	using namespace EventHandling;

	public ref class RestApiWP sealed
	{
	public:
		RestApiWP()
		{
			rest = new RestApi();
			publisher = ref new Publisher();

			publisher->FireEvent +=
				ref new CustomEventHandler(
					this,
					&RestApiWP::MyEventHandler);
		}

		void MyEventHandler(Publisher^ mc, size_t nativeClassPtr)
		{
			void *ptr = (void*)nativeClassPtr;
			Event* evnt = (Event*)ptr;

			switch (evnt->type)
			{
			case Event::EventType::PostComment:
				rest->PostComment(dynamic_cast<PostCommentEvent*>(evnt)->getComment());
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
		RestApi* rest;
	};
}