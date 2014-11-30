// ThreadFunctionObjectWithTimedMutex.cpp
#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: mId(id), mNumIterations(numIterations)
	{
	}

	void operator()() const
	{
		for (int i = 0; i < mNumIterations; ++i) {
			unique_lock<timed_mutex> lock(mTimedMutex, chrono::milliseconds(200));
			if (lock) {
				cout << "Counter " << mId << " has value ";
				cout << i << endl;
			} else {
				// Lock not obtained in 200 ms
			}
		}
	}

protected:
	int mId;
	int mNumIterations;
	static timed_mutex mTimedMutex;
};

timed_mutex Counter::mTimedMutex;

int main()
{
	cout.sync_with_stdio(true); // Make sure cout is thread-safe

	// Using C++11 initialization syntax
	thread t1{Counter(1, 20)};

	// Using named variable
	Counter c(2, 12);
	thread t2(c);

	// Using temporary
	thread t3(Counter(3, 10));

	// Wait for threads to finish
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
