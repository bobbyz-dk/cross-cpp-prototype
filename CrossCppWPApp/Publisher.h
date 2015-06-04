#pragma once

#include "Event.h"

namespace EventHandling
{
	ref class Publisher;
	public delegate void CustomEventHandler(Publisher^ sender, size_t nativeClassPtr);

	public ref class Publisher sealed
	{
	public:
		Publisher() {}
		event CustomEventHandler^ FireEvent;

		void LoadLastTweet(Platform::String^ screenName)
		{
			std::wstring ws(screenName->Data());
			std::string str(ws.begin(), ws.end());
			LoadLastTweetEvent *evnt = new LoadLastTweetEvent(str);
			void *v_ptr = evnt;
			size_t ptr = (size_t)v_ptr;
			FireEvent(this, ptr);
		}

		void LastTweetLoaded(Platform::String^ tweet)
		{
			std::wstring ws(tweet->Data());
			std::string str(ws.begin(), ws.end());
			LastTweetLoadedEvent *evnt = new LastTweetLoadedEvent(str);
			void *v_ptr = evnt;
			size_t ptr = (size_t)v_ptr;
			FireEvent(this, ptr);
		}

		void PostComment(Platform::String^ _text, Platform::String^ _email)
		{
			std::wstring ws_text(_text->Data());
			std::string text(ws_text.begin(), ws_text.end());
			std::wstring ws_email(_email->Data());
			std::string email(ws_email.begin(), ws_email.end());
			PostCommentEvent *evnt = new PostCommentEvent(Comment(text, email));
			void *v_ptr = evnt;
			size_t ptr = (size_t)v_ptr;
			FireEvent(this, ptr);
		}
	};
}