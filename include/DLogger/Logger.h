#ifndef __DLOGGER_LOGGER_H
#define __DLOGGER_LOGGER_H

#include <string>

namespace LOGGER
{
	void setProject(const std::string& name,
					const std::string& version);
					
	void setFileLogging(const bool& should_file_log,
						const std::string& path);
						
	void setConsoleLoggint(const bool& should_console_log);
	
	void start();
	
	void end();
}

#endif