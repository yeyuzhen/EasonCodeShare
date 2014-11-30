// is_same.cpp
#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template<typename T1, typename T2>
void same_helper(const T1& t1, const T2& t2, bool b)
{
	cout << "'" << t1 << "' and '" << t2 << "' are ";
	cout << (b ? "the same types." : "different types.") << endl;
}

template<typename T1, typename T2>
void same(const T1& t1, const T2& t2)
{
	same_helper(t1, t2, is_same<T1, T2>::value);
}

int main()
{
	same(1, 32);
	same(1, 3.01);
	same(3.01, string("Test"));

	return 0;
}
