#include "log.h"
#include <android/log.h>

#define LOGD(TAG,...) __android_log_print(ANDROID_LOG_DEBUG  , TAG,__VA_ARGS__)


void logdebug(std::string tag, std::string arg)
{
	const char *cTag = tag.c_str();
	const char *cArg = arg.c_str();
	LOGD(cTag, cArg);
}