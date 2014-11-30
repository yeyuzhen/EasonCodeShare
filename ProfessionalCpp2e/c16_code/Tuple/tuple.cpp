#include <iostream>
#include <string>
#include <tuple> 
#include <functional>  // for ref and cref
#include <typeinfo>

using namespace std;

int main()
{
	typedef tuple<int, string, bool> MyTuple;
	MyTuple t1(16, "Test", true);
	cout << "t1 = (" << get<0>(t1) << ", " << get<1>(t1)
		 << ", " << get<2>(t1) << ")" << endl;
	cout << "Tuple Size = " << tuple_size<MyTuple>::value << endl;
	cout << "Type of get<1>(t1) = " << typeid(get<1>(t1)).name() << endl;

	double d = 3.14;
	string str1 = "Test";
	// t2 will be tuple<int, double&, string&, const string&>
	auto t2 = make_tuple(16, ref(d), ref(str1), cref(str1));

	cout << "d = " << d << endl;
	get<1>(t2) *= 2;
	cout << "d = " << d << endl;

	cout << "str = " << str1 << endl;
	get<2>(t2) = "Hello";
	//get<3>(t2) = "Hello";	// ERROR: would be an error because of cref
	cout << "str = " << str1 << endl;

	return 0;
}