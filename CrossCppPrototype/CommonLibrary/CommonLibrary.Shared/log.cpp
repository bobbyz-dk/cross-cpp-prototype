#include "log.h"
#include <windows.h>

void logdebug(std::string tag, std::string arg)
{
	std::string str = tag + ", " + arg + "\n";
	std::wstring ws;
	ws.assign(str.begin(), str.end());
	OutputDebugStringW(ws.c_str());
}