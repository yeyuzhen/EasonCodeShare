// ExceptionsWithThreads.cpp

#include <thread>
#include <iostream>
#include <stdexcept>

using namespace std;

void doSomeWork() throw(runtime_error)
{
	for (int i = 0; i < 5; ++i)
		cout << i << endl;
	cout << "Thread throwing a runtime_error exception..." << endl;
	throw runtime_error("Exception from thread");
}

void threadFunc(exception_ptr& err)
{
	try {
		doSomeWork();
	} catch (...) {
		cout << "Thread caught exception, returning exception..." << endl;
		err = current_exception();
	}
}

void doWorkInThread() throw(runtime_error)
{
	exception_ptr error;
	// Launch background thread
	thread t{threadFunc, ref(error)};
	// Wait for thread to finish
	t.join();
	// See if thread has thrown any exception
	if (error)
	{
		cout << "Main thread received exception, rethrowing it..." << endl;
		rethrow_exception(error);
	}
	else
		cout << "Main thread did not receive any exception." << endl;
}

int main()
{
	cout.sync_with_stdio(true); // Make sure cout is thread-safe

	try {
		doWorkInThread();
	} catch (const exception& e) {
		cout << "Main function caught: '" << e.what() << "'" << endl;
	}
	return 0;
}
