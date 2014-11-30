#include <iostream>
#include <string>
#include <utility> 

using namespace std;

int main()
{
	pair<int, string> p1(16, "Hello World");
	pair<bool, float> p2(true, 0.123f);
	cout << "p1 = (" << p1.first << ", " << p1.second << ")" << endl;
	cout << "p2 = (" << p2.first << ", " << p2.second << ")" << endl;

	return 0;
}
