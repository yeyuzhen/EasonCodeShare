// double_checked_locking.cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

class MyClass
{
public:
	void init() {cout << "Init" << endl;}
};

MyClass var;
bool initialized = false;
mutex mut;

void func()
{
	if (!initialized) {
		unique_lock<mutex> lock(mut);
		if (!initialized) {
			var.init();
			initialized = true;
		}
	}
	cout << "OK" << endl;
}

int main()
{
	cout.sync_with_stdio(true); // Make sure cout is thread-safe

	vector<thread> threads;
	
	for (int i = 0; i < 5; ++i)
		threads.push_back(thread{func});
	
	for (auto& t : threads)
		t.join();

	return 0;
}
