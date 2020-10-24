#include <iostream>
#include <DLogger/Logger.h>

int main()
{
	LOGGER::setProject("DLogger Test", "1.0");
	LOGGER::setFileLogging(true, "Log.txt");
	LOGGER::start();
	LOGGER::end();
	return 0;
}