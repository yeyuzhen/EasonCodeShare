// LoggerAdapter.h
#include <string>
#include <iostream>

class Logger
{
public:
	static const std::string kLogLevelDebug;
	static const std::string kLogLevelInfo;
	static const std::string kLogLevelError;

	Logger() {
		std::cout << "Logger constructor" << std::endl;
	}

	void log(const std::string& level, const std::string& str) {
		std::cout << level << ": " << str << std::endl;
	}
};
const std::string Logger::kLogLevelDebug = "DEBUG";
const std::string Logger::kLogLevelInfo = "INFO";
const std::string Logger::kLogLevelError = "ERROR";

class NewLoggerInterface
{
public:
	virtual void log(const std::string& str) = 0;
};

class NewLoggerAdapter : public NewLoggerInterface, private Logger
{
public:
	NewLoggerAdapter() {
		std::cout << "NewLoggerAdapter constructor" << std::endl;
	}

	virtual void log(const std::string& str) {
		Logger::log(Logger::kLogLevelInfo, str);
	}
};
