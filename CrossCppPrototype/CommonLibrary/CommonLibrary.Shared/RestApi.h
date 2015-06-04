#pragma once
#include "Comment.h"

namespace RestApiSpace
{
	using namespace model;

	class RestApi
	{
	public:
		RestApi();
		~RestApi();
		void PostComment(Comment comment);
	};
}