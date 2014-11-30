// is_integral_simple.cpp
#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

int main()
{
	if (is_integral<int>::value) {
		cout << "int is integral" << endl;
	} else {
		cout << "int is not integral" << endl;
	}

	if (is_class<string>::value) {
		cout << "string is a class" << endl;
	} else {
		cout << "string is not a class" << endl;
	}

	return 0;
}
