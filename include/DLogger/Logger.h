#ifndef __DLOGGER_LOGGER_H
#define __DLOGGER_LOGGER_H

#include <string>

/**
*	@brief This namespace capsules all Logger functions
*	To use the logger a project name and version is to be specified. This will be used
*	in the header of the logger.
*	Console logging is turned on by default.
*		To disable it call setConsoleLogging(false);
*	File logging is turned off by default
*		To enable it call setFileLogging(true, PATH_TO_LOG_FILE);
*	
*	Logging starts when calling
*		LOGGER::start();
*	Logging ends when calling
*		LOGGER::end();
*/
namespace LOGGER
{
	void setProject(const std::string& name,
					const std::string& version);
					
	void setFileLogging(const bool& should_file_log,
						const std::string& path);
						
	void setConsoleLogging(const bool& should_console_log);
	
	void start();
	
	void end();
}

#endif