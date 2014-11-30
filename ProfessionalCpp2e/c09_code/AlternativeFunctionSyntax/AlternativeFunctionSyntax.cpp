// AlternateFunctionSyntax.cpp

#include <iostream>

using namespace std;

// Function using new alternate syntax
auto func(int i) -> int
{
    return i+2;
}

auto main() -> int
{
    cout << func(3) << endl;

    return 0;
}
