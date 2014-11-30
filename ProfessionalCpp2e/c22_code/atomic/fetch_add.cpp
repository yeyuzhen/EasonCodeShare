// fetch_add.cpp
#include <iostream>
#include <atomic>

using namespace std;

int main()
{
	atomic<int> value(10);
	cout << "Value = " << value << endl;
	int fetched = value.fetch_add(4);
	cout << "Fetched = " << fetched << endl;
	cout << "Value = " << value << endl;

	return 0;
}
