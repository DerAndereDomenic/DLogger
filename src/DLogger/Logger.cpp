#include <DLogger/Logger.h>
#include <iostream>

namespace __dlogger_Detail
{
	std::string project_name;
	std::string version;
	
	void loggerHeader();
}

void 
LOGGER::setProject(const std::string& name,
				   const std::string& version)
{
	__dlogger_Detail::project_name = name;
	__dlogger_Detail::version = version;
}
					
void 
LOGGER::setFileLogging(const bool& should_file_log,
					   const std::string& path)
{
	
}
						
void 
LOGGER::setConsoleLoggint(const bool& should_console_log)
{
	
}
	
void 
LOGGER::start()
{
	__dlogger_Detail::loggerHeader();
}
	
void 
LOGGER::end()
{
	
}

void 
__dlogger_Detail::loggerHeader()
{
	std::cout << "##########################################################################" << std::endl;
	std::cout << project_name << " " << version << std::endl;
	std::cout << "##########################################################################" << std::endl;
}