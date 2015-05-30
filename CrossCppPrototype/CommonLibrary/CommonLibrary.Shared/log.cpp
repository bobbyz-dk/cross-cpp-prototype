#include "log.h"

void logdebug(std::string tag, std::string arg)
{
	printf("%s, %s", tag.c_str(), arg.c_str());
}