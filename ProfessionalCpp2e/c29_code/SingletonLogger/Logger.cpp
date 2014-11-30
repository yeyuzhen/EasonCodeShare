// Implementation of a singleton logger class.
#include <stdexcept>
#include "Logger.h"

using namespace std;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo = "INFO";
const string Logger::kLogLevelError = "ERROR";

const char* const Logger::kLogFileName = "log.out";

// The static instance will be constructed when the program starts and
// destructed when it ends.
Logger Logger::sInstance;

Logger& Logger::instance()
{
	return sInstance;
}

Logger::~Logger()
{
	mOutputStream.close();
}

Logger::Logger()
{
	mOutputStream.open(kLogFileName, ios_base::app);
	if (!mOutputStream.good()) {
		throw runtime_error("Unable to initialize the Logger!");
	} 
}

void Logger::log(const string& inMessage, const string& inLogLevel)
{
	mOutputStream << inLogLevel << ": " << inMessage << endl;
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel)
{
	for (size_t i = 0; i < inMessages.size(); i++) {
		log(inMessages[i], inLogLevel);
	}
}
