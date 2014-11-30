#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Definition of a singleton logger class, implemented with static methods.
class Logger
{
public:
	static const std::string kLogLevelDebug;
	static const std::string kLogLevelInfo;
	static const std::string kLogLevelError;

	// Logs a single message at the given log level
	static void log(const std::string& inMessage, 
		const std::string& inLogLevel);

	// Logs a vector of messages at the given log level
	static void log(const std::vector<std::string>& inMessages, 
		const std::string& inLogLevel);

	// Closes the log file
	static void teardown();

protected:
	static void init();

	static const char* const kLogFileName;

	static bool sInitialized;
	static std::ofstream sOutputStream;

private:
	Logger() {}
};
