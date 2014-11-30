#include "RingBuffer.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

RingBuffer debugBuf;

class ComplicatedClass
{
public:
	ComplicatedClass() {}
};

class UserCommand
{
public:
	UserCommand() {}
};

ostream& operator<<(ostream& ostr, const ComplicatedClass& src);
ostream& operator<<(ostream& ostr, const UserCommand& src);
UserCommand getNextCommand(ComplicatedClass* obj);
void processUserCommand(UserCommand& cmd);
void trickyFunction(ComplicatedClass* obj) throw(exception);

int main(int argc, char* argv[])
{
	// Print the command-line arguments
	for (int i = 0; i < argc; i++) {
		debugBuf.addEntry(argv[i]);
	}

	ComplicatedClass obj;
	trickyFunction(&obj);

	// Print the current contents of the debug buffer to cout
	cout << debugBuf;

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
	// trace log the values with which this function starts
	ostringstream ostr;
	ostr << __func__ << "(): given argument: " << *obj;
	debugBuf.addEntry(ostr.str());

	for (size_t i = 0; i < 100; ++i) {
		UserCommand cmd = getNextCommand(obj);

		ostringstream ostr;
		ostr << __func__ << "(): retrieved cmd " << cmd;
		debugBuf.addEntry(ostr.str());

		try {
			processUserCommand(cmd);
		} catch (const exception& e) {
			string msg = __func__;
			msg += "(): received exception from processUserCommand():";
			msg += e.what();
			debugBuf.addEntry(msg);
			throw;
		}
	}
}
