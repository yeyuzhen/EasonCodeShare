#include "TypeInference.h"
#include <iostream>
#include <string>

using namespace std;

MyInt MyInt::operator+(const MyString& rhs) const
{
	return m_i + stoi(rhs.getString());
}

MyString MyString::operator+(const MyInt& rhs) const
{
	string str = m_str;
	str.append(to_string((long long)rhs.getInt()));
	return str;
}

template<typename T1, typename T2, typename Result>
Result DoAddition(const T1& t1, const T2& t2)
{
	return t1 + t2;
}

template<typename T1, typename T2>
auto DoAddition2(const T1& t1, const T2& t2) -> decltype(t1 + t2)
{
	return t1 + t2;
}

int main()
{
	MyInt i(4);
	MyString str("5");
	MyInt a = i + str;
	MyString b = str + i;

	auto c = DoAddition<MyInt, MyString, MyInt>(i, str);
	auto d = DoAddition2(i, str);
	auto e = DoAddition2(str, i);

	return 0;
}
