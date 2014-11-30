#include <string>

// Forward class declarations
class MyInt;
class MyString;

class MyInt
{
public:
	MyInt(int i) : m_i(i) {}
	MyInt operator+(const MyString& rhs) const;
	int getInt() const { return m_i; }
protected:
	int m_i;
};

class MyString
{
public:
	MyString(std::string str) : m_str(str) {}
	MyString operator+(const MyInt& rhs) const;
	const std::string& getString() const { return m_str; }
protected:
	std::string m_str;
};