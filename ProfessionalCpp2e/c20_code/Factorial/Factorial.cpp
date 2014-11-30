// Factorial.cpp
#include <iostream>

using namespace std;

template<long long f>
class Factorial
{
public:
	static const long long val = (f*Factorial<f-1>::val);
};

template<>
class Factorial<1>
{
public:
	static const long long val = 1;
};

int main()
{
	cout << Factorial<6>::val << endl;
	return 0;
}
