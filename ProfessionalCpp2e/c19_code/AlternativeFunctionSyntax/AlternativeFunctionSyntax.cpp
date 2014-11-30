// AlternateFunctionSyntax.cpp

#include <iostream>

using namespace std;

// The following will not compile, because RetType is unknown.
//template<typename Type1, typename Type2>
//RetType myFunc(const Type1& t1, const Type2& t2) {return t1 + t2;}

// The following will not compile because t1 and t2 are used
// too early on the prototype line
//template<typename Type1, typename Type2>
//decltype(t1+t2) myFunc(const Type1& t1, const Type2& t2) {return t1 + t2;} 

// Using the alternate function syntax, the following will compile and work
template<typename Type1, typename Type2>
auto myFunc(const Type1& t1, const Type2& t2) -> decltype(t1+t2)
     {return t1 + t2;}

auto main() -> int
{
    cout << myFunc(2, 4) << endl;

    return 0;
}
