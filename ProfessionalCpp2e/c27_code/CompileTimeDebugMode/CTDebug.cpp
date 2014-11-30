#include <exception>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#ifdef DEBUG_MODE
	class Logger
	{
	public:
		template<typename... Args>
		static void log(const Args&... args)
		{
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
	};
	const char* Logger::msDebugFileName = "debugfile.out";

	#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)
#else
	#define log(...)
#endif


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

ostream& operator<<(ostream& ostr, const ComplicatedClass& src);
ostream& operator<<(ostream& ostr, const UserCommand& src);
UserCommand getNextCommand(ComplicatedClass* obj);
void processUserCommand(UserCommand& cmd);
void trickyFunction(ComplicatedClass* obj) throw(exception);

int main(int argc, char* argv[])
{
#ifdef DEBUG_MODE
	// Print the command-line arguments to the trace
	for (int i = 0; i < argc; i++) {
		log(argv[i]);
	}
#endif

	ComplicatedClass obj;
	trickyFunction(&obj);
	// Rest of the function not shown
	return 0;
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
