#pragma once
#include "Event.h"
#include "RestApi.h"

namespace RestApiSpace
{
	class RestApiWP
	{
	public:
		RestApiWP();

	private:
		RestApi* rest;
	};
}