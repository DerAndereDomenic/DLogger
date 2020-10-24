#include <iostream>
#include <DLogger/Logger.h>

int main()
{
	LOGGER::setProject("DLogger Test", "1.0");
	LOGGER::setFileLogging(true, "Log.txt");
	LOGGER::setConsoleLogging(true);
	LOGGER::start();
	return 0;
}