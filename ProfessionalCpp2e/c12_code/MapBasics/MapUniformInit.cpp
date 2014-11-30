#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> m = {
        {"Marc G.", 123},
        {"Zulija N.", 456},
        {"John D.", 369}
    };

    for (auto& p : m)
        cout << p.first << " = " << p.second << endl;

    return 0;
}
