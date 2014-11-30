// enable_if.cpp
#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template<typename T1, typename T2>
void check_type(const T1& t1, const T2& t2,
	typename enable_if<is_same<T1, T2>::value>::type* p = nullptr)
{
	cout << "'" << t1 << "' and '" << t2 << "' ";
	cout << "are the same types." << endl;
}
template<typename T1, typename T2>
void check_type(const T1& t1, const T2& t2,
	typename enable_if<!is_same<T1, T2>::value>::type* p = nullptr)
{
	cout << "'" << t1 << "' and '" << t2 << "' ";
	cout << "are different types." << endl;
}

int main()
{
	check_type(1, 32);
	check_type(1, 3.01);
	check_type(3.01, string("Test"));

	return 0;
}
