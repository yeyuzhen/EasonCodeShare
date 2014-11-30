#include <iostream>
#include <string>
#include "TemplateIntroduction.h"

using namespace std;

int main()
{
    // Wrap an int array
    MyArray<int> arrInt(10);
    cout << "Array size: " << arrInt.getSize() << endl;
    arrInt.at(3) = 42;
    cout << "arr[3] = " << arrInt.at(3) << endl;
    try {
        arrInt.at(10) = 3;
    } catch (const exception& e) {
        cout << "Caught exception: '" << e.what() << "'" << endl;
    }

    // Wrap a std::string array
    MyArray<string> arrString(5);
    cout << "Array size: " << arrString.getSize() << endl;
    arrString.at(3) = "This is a test";
    cout << "arr[3] = " << arrString.at(3) << endl;
    try {
        arrString.at(10) = 3;
    } catch (const exception& e) {
        cout << "Caught exception: '" << e.what() << "'" << endl;
    }

    return 0;
}
