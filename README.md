# DLOGGER

A simple logger to log messages in your C/C++ projects. You can log directly into the console and/or into a log file. The logger differentiates between four priority levels (DEBUG < INFO < WARNING < ERROR). The user can choose the lowest priority that still should be logged for both of the outputs separately.

# Building
The Logger is supported and tested on windows and Linux Ubuntu. The build system is CMake. Building the project will also generate the executable DLoggerTest to test the output of the logger. <br>
<br>
**Windows** <br>
Both the Visual Studio 2019 and MinGW should work. When using Visual Studio and selecting the install target, a bin folder inside the project directory is created with the static lib files. <br>
<br>
**Linux/Ubuntu**<br>
There are no dependencies to be installed. Just building the project should generate the library files.

# Example
One example can be seen under src/source.cpp. A more in depth example can be seen here: <br>
```
#include <DLogger/Logger.h>
...
//Set project information for the header
LOGGER::setProject("Project Name", "Project Version");
//Enable file logging and set a log file path
LOGGER::setFileLogging(true, "Log.txt");
//Don't show debug messages in console
LOGGER::setMinConsoleLevel(LoggerLevel::INFO);

//Start the logger
LOGGER::start();

//Start logging messages
LOGGER::DEBUG("This is a debug message\n");
LOGGER::INFO("This is an info message\n");
LOGGER::WARNING("This is a warning message\n");
LOGGER::ERROR("This is an error message\n");

//End logging
LOGGER::end();
```