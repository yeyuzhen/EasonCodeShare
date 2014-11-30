#include <iostream>
#include <string>
#include <tuple> 
using namespace std;

int main()
{
	tuple<int, string, bool> t1(16, "Test", true);

	int i = 0;
	string str;
	bool b = false;
	cout << "Before: i = " << i << ", str = \"" << str << "\", b = " << b << endl;
	tie(i, str, b) = t1;
	cout << "After:  i = " << i << ", str = \"" << str << "\", b = " << b << endl;

	return 0;
}