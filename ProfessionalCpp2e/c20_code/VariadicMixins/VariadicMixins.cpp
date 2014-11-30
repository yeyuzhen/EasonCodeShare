#include <iostream>

using namespace std;

class Mixin1
{
public:
	Mixin1(int i) : m_i(i) {}
	virtual void Mixin1Func() {cout << "Mixin1: " << m_i << endl;}
protected:
	int m_i;
};

class Mixin2
{
public:
	Mixin2(int i) : m_i(i) {}
	virtual void Mixin2Func() {cout << "Mixin2: " << m_i << endl;}
protected:
	int m_i;
};

template<typename... Mixins>
class MyClass : public Mixins...
{
public:
	MyClass(const Mixins&... mixins) : Mixins(mixins)... {}
};

int main()
{
	MyClass<Mixin1, Mixin2> a(Mixin1(11), Mixin2(22));
	a.Mixin1Func();
	a.Mixin2Func();

	MyClass<Mixin1> b(Mixin1(33));
	b.Mixin1Func();
	//b.Mixin2Func();    // Error: does not compile.

	return 0;
}
