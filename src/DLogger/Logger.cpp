#include <DLogger/Logger.h>
#include <iostream>
#include <cstdint>
#include <sstream>
#include <fstream>

namespace __dlogger_Detail
{
	std::string project_name;
	std::string version;
	
	bool initialized = false;
	bool should_file_log = false;
	bool should_console_log = true;
	LoggerLevel minConsoleLevel = LoggerLevel::DEBUG;
	LoggerLevel minFileLevel = LoggerLevel::DEBUG;
	
	std::fstream out_file;
	std::string prefix[4] =
	{
		"[  Debug  ] ",
		"[  Info   ] ",
		"[ Warning ] ",
		"[  Error  ] "
	};
	uint32_t status[4] = {0,0,0,0};
	
	void loggerHeader();
	
	void loggerFooter();
	
	void writeLog(const std::string& log);
	
	void writeLogLevel(const LoggerLevel& level, const std::string& log);
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
	__dlogger_Detail::should_file_log = should_file_log;
	__dlogger_Detail::out_file = std::fstream(path, std::ios::out);
}
						
void 
LOGGER::setConsoleLogging(const bool& should_console_log)
{
	__dlogger_Detail::should_console_log = should_console_log;
}
	
void 
LOGGER::start()
{
	__dlogger_Detail::initialized = true;
	__dlogger_Detail::loggerHeader();
}
	
void 
LOGGER::end()
{
	__dlogger_Detail::out_file.close();
	__dlogger_Detail::initialized = false;
}

void 
LOGGER::setMinConsoleLevel(const LoggerLevel& level)
{
	__dlogger_Detail::minConsoleLevel = level;
}

void 
LOGGER::setMinFileLevel(const LoggerLevel& level)
{
	__dlogger_Detail::minFileLevel = level;
}

void 
LOGGER::DEBUG(const std::string& log)
{
	__dlogger_Detail::writeLogLevel(LoggerLevel::DEBUG, log);
}

void 
LOGGER::INFO(const std::string& log)
{
	__dlogger_Detail::writeLogLevel(LoggerLevel::INFO, log);
}

void 
LOGGER::WARNING(const std::string& log)
{
	__dlogger_Detail::writeLogLevel(LoggerLevel::WARNING, log);
}
	
void 
LOGGER::ERROR(const std::string& log)
{
	__dlogger_Detail::writeLogLevel(LoggerLevel::ERROR, log);
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
__dlogger_Detail::loggerFooter()
{
	uint32_t white_space = 80;
	
	std::stringstream ss;
	
	ss << "#" << std::string(white_space, '-') << "#" << std::endl;
	writeLog(ss.str());
	
	ss.str(std::string());
	ss << "#" << " Warnings: " << status[2] << std::endl;
	writeLog(ss.str());
	
	ss.str(std::string());
	ss << "#" << " Errors: " << status[3] << std::endl;
	writeLog(ss.str());
	
	ss.str(std::string());
	ss << "#" << std::string(white_space, '-') << "#" << std::endl;
	writeLog(ss.str());
}

void 
__dlogger_Detail::writeLog(const std::string& log)
{
	if(!initialized) return;
	
	if(should_console_log)
	{
		std::cout << log;
	}
	
	if(should_file_log)
	{
		out_file << log;
	}
}

void 
__dlogger_Detail::writeLogLevel(const LoggerLevel& level, const std::string& log)
{
	if(!initialized) return;
	
	if(should_console_log && level >= minConsoleLevel)
	{
		std::cout << prefix[static_cast<int32_t>(level)] << log;
	}
	
	if(should_file_log && level >= minFileLevel)
	{
		out_file << prefix[static_cast<int32_t>(level)] << log;
	}
	
	++status[static_cast<int32_t>(level)];
}