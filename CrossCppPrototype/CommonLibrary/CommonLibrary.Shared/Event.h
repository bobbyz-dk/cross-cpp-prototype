#pragma once
#include <string>
#include "Comment.h"

namespace EventHandling
{

	using namespace std;
	using namespace model;

	class Event
	{
	public:
		enum EventType
		{
			LoadLastTweet,
			LastTweetLoaded,
			PostComment
		};

		EventType type;
		Event(EventType type);
		Event(void* ptr);
		virtual EventType getType();
	};

	class LoadLastTweetEvent : public Event
	{
	private:
		string screenName;
	public:
		LoadLastTweetEvent(string _screenName);
		string getScreenName();
	};

	class LastTweetLoadedEvent : public Event
	{
	private:
		string tweet;
	public:
		LastTweetLoadedEvent(string tweet);
		string getTweet();
	};

	class PostCommentEvent : public Event
	{
	private:
		Comment comment;
	public:
		PostCommentEvent(Comment comment);
		Comment getComment();
	};
}