#include "pch.h"
#include "RestApi.h"
#include "Poco/Net/HTTPClientSession.h"

namespace RestApiSpace
{

	RestApi::RestApi()
	{
	}


	RestApi::~RestApi()
	{
	}

	void RestApi::PostComment(Comment comment)
	{
		printf("Comment: %s", comment.ToString());
	}
}