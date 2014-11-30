#include <iostream>

using namespace std;

void g()
{
	throw 2;
}

void f()
{
	try {
		g();
	} catch (int i) {
		cout << "caught in f: " << i << endl;
		throw;  // rethrow
	}
}

int main()
{
	try {
		f();
	} catch (int i) {
		cout << "caught in main: " << i << endl;
	}
	return 0;
}