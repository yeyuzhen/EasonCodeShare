#include <functional>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

class myIsDigit : public unary_function<char, bool>
{
public:
	bool operator() (char c) const { return ::isdigit(c); }
};

bool isNumber(const string& str)
{
	auto end = str.end();
	auto it = find_if(str.begin(), end, not1(myIsDigit()));
	return (it == end);
}

int main()
{

	cout << isNumber("12345") << endl;
	cout << isNumber("hello") << endl;
	cout << isNumber("1234a") << endl;

	return 0;
}
