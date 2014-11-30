// call_once.cpp
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

class Data
{
public:
	void operator()()
	{
		call_once(mOnceFlag, &Data::init, this);
		// Do work
		cout << "Work" << endl;
	}
protected:
	void init()
	{
		cout << "init()" << endl;
		mMemory = new char[24];
	}
	mutable once_flag mOnceFlag;
	mutable char* mMemory;
};

int main()
{
	cout.sync_with_stdio(true); // Make sure cout is thread-safe

	Data d;
	thread t1{ref(d)};
	thread t2{ref(d)};
	thread t3{ref(d)};
	t1.join();
	t2.join();
	t3.join();
	return 0;
}
