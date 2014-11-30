#include <iostream>

using namespace std;

// Increment value using lvalue reference parameter.
void incr(int& value)
{
    cout << "increment with lvalue reference" << endl;
    ++value;
}

// Increment value using rvalue reference parameter.
void incr(int&& value)
{
    cout << "increment with rvalue reference" << endl;
    ++value;
}

int main()
{
    int a = 10, b = 20;

	// Increment a named variable
    incr(a);      // Will call incr(int& value)
	cout << "  a=" << a << ", b=" << b << endl;

	// Increment an expression
    incr(a + b);  // Will call incr(int&& value)
    cout << "  a=" << a << ", b=" << b << endl;

    // Increment a literal
    incr(3);      // Will call incr(int&& value)
    cout << "  a=" << a << ", b=" << b << endl;

    // Increment a named variable and force to use rvalue reference method
    incr(std::move(b));  // Will call incr(int&& value)
    cout << "  a=" << a << ", b=" << b << endl;

	return 0;
}
