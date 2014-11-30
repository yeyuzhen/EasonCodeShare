// async.cpp
#include <iostream>
#include <future>

using namespace std;

int calculate()
{
	return 123;
}

int main()
{
	auto fut = async(calculate);
	//auto fut = async(launch::async, calculate);
	//auto fut = async(launch::deferred, calculate);

	// Do some more work...

	// Get result
	int res = fut.get();
	cout << res << endl;

	return 0;
}
