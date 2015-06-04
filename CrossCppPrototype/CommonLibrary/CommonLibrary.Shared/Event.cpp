#include "Event.h"

namespace EventHandling
{

	using namespace std;

	Event::Event(void* ptr)
	{
		Event* e = (Event*)ptr;
		printf("EventType: %d", e->getType());
	}

	Event::Event(EventType type)
	{
		this->type = type;
	}

	Event::EventType Event::getType()
	{
		return type;
	}

	LoadLastTweetEvent::LoadLastTweetEvent(string _screenName) : Event(Event::EventType::LoadLastTweet)
	{
		screenName = _screenName;
	}

	string LoadLastTweetEvent::getScreenName()
	{
		return screenName;
	}

	LastTweetLoadedEvent::LastTweetLoadedEvent(string _tweet) : Event(Event::EventType::LastTweetLoaded)
	{
		tweet = _tweet;
	}

	string LastTweetLoadedEvent::getTweet()
	{
		return tweet;
	}

	PostCommentEvent::PostCommentEvent(Comment _comment) : Event(Event::EventType::PostComment)
	{
		comment = _comment;
	}

	Comment PostCommentEvent::getComment()
	{
		return comment;
	}
}