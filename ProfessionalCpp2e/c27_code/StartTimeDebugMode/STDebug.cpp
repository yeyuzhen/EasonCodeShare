#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Logger
{
public:
	static void enableLogging(bool enable) { msLoggingEnabled = enable; }
	static bool isLoggingEnabled() { return msLoggingEnabled; }

	template<typename... Args>
	static void log(const Args&... args)
	{
		if (!msLoggingEnabled)
			return;

		ofstream ofs(msDebugFileName, ios_base::app);
		if (ofs.fail()) {
			cerr << "Unable to open debug file!" << endl;
			return;
		}
		logHelper(ofs, args...);
		ofs << endl;
	}

protected:
	template<typename T1>
	static void logHelper(ofstream& ofs, const T1& t1)
	{
		ofs << t1;
	}

	template<typename T1, typename... Tn>
	static void logHelper(ofstream& ofs, const T1& t1, const Tn&... args)
	{
		ofs << t1;
		logHelper(ofs, args...);
	}

	static const char* msDebugFileName;
	static bool msLoggingEnabled;
};
const char* Logger::msDebugFileName = "debugfile.out";
bool Logger::msLoggingEnabled = false;

#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)


class ComplicatedClass
{
public:
	ComplicatedClass() {}

	// class details omitted for brevity
};

class UserCommand
{
public:
	UserCommand() {}

	// class details not shown for brevity
};

bool isDebugSet(int argc, char* argv[]);
ostream& operator<<(ostream& ostr, const ComplicatedClass& src);
ostream& operator<<(ostream& ostr, const UserCommand& src);
UserCommand getNextCommand(ComplicatedClass* obj);
void processUserCommand(UserCommand& cmd);
void trickyFunction(ComplicatedClass* obj) throw(exception);

int main(int argc, char* argv[])
{
	Logger::enableLogging(isDebugSet(argc, argv));

	if (Logger::isLoggingEnabled()) {
		// Print the command-line arguments to the trace
		for (int i = 0; i < argc; i++) {
			log(argv[i]);
		}
	}

	ComplicatedClass obj;
	trickyFunction(&obj);
	// Rest of the function not shown
	return 0;
}

bool isDebugSet(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-d") == 0) {
			return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& ostr, const ComplicatedClass& src)
{
	ostr << "ComplicatedClass";
	return ostr;
}

ostream& operator<<(ostream& ostr, const UserCommand& src)
{
	ostr << "UserCommand";
	return ostr;
}

UserCommand getNextCommand(ComplicatedClass* obj)
{
	UserCommand cmd;
	return cmd;
}

void processUserCommand(UserCommand& cmd)
{
	// details omitted for brevity
}

void trickyFunction(ComplicatedClass* obj) throw(exception)
{
	log("given argument: ", *obj);

	for (size_t i = 0; i < 100; ++i) {
		UserCommand cmd = getNextCommand(obj);

		log("retrieved cmd ", i, ": ", cmd);
		try {
			processUserCommand(cmd);
		} catch (const exception& e) {
			log("received exception from processUserCommand(): ", e.what());
			throw;
		}
	}
}
