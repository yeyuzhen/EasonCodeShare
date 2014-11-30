// bind.cpp
#include <iostream>
#include <string>
#include <functional>

using namespace std;
using namespace std::placeholders;

void func(int num, const string& str)
{
	cout << "func(" << num << ", " << str << ")" << endl;
}

void overloaded(int num) {}
void overloaded(float f) {}

int main()
{
	// Bind second argument to a fixed value.
	string str = "abc";
	auto f1 = bind(func, _1, str);
	f1(16);

	// rearrange arguments
	auto f2 = bind(func, _2, _1);
	f2("Test", 32);

	// Bind overloaded function
	//auto f3 = bind(overloaded, _1);               // ERROR
	auto f4 = bind((void(*)(float))overloaded, _1);	// OK
	
	return 0;
}

