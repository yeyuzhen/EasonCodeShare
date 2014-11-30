#include <functional>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

bool isNumber(const string& str)
{
	auto end = str.end();
	
	// Using old and deprecated ptr_fun
	//auto it = find_if(str.begin(), end, not1(ptr_fun(::isdigit)));
	
	// Using C++11 lambda
	//auto it = find_if(str.begin(), end, 
	//	[](char c){ return !::isdigit(c); });

	// Using C++11 find_if_not()
	auto it = find_if_not(str.begin(), end, ::isdigit); 

	return (it == end);
}

int main()
{

	cout << isNumber("12345") << endl;
	cout << isNumber("hello") << endl;
	cout << isNumber("1234a") << endl;

	return 0;
}
