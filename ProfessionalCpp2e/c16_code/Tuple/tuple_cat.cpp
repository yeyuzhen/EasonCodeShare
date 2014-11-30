#include <iostream>
#include <string>
#include <tuple> 
using namespace std;

int main()
{
	tuple<int, string, bool> t1(16, "Test", true);
	tuple<double, string> t2(3.14, "string 2");
	auto t3 = tuple_cat(t1, t2);
	cout << get<0>(t3) << endl;
	cout << get<1>(t3) << endl;
	cout << get<2>(t3) << endl;
	cout << get<3>(t3) << endl;
	cout << get<4>(t3) << endl;

	return 0;
}
