// packaged_task.cpp
#include <iostream>
#include <future>

using namespace std;

int main()
{
	packaged_task<int(int, int)> task([](int i1, int i2) {return i1+i2;});
	auto fut = task.get_future();
	task(2, 3);
	int res = fut.get();
	cout << res << endl;

	return 0;
}
