#include <DLogger/Logger.h>
#include <iostream>
#include <cstdint>
#include <sstream>

namespace __dlogger_Detail
{
	std::string project_name;
	std::string version;
	
	bool should_file_log = false;
	bool should_console_log = false;
	
	void loggerHeader();
	
	void writeLog(const std::string& log);
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
	uint32_t white_space = 80;
	uint32_t name_ver_size = project_name.size() + version.size() + 1;
	uint32_t rem_white_space = (white_space - name_ver_size)/2;
	
	std::stringstream ss;
	
	ss << "#" << std::string(white_space, '-') << "#" << std::endl;
	writeLog(ss.str());
	
	ss.str(std::string());
	ss << "#" << std::string(rem_white_space, ' ') << project_name << " " << version << std::string(rem_white_space, ' ') << "#" <<std::endl;
	writeLog(ss.str());
	
	ss.str(std::string());
	ss << "#" << std::string(white_space, '-') << "#" << std::endl;
	writeLog(ss.str());
}

void 
__dlogger_Detail::writeLog(const std::string& log)
{
	std::cout << log;
}