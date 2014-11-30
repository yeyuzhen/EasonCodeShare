#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int main()
{
    map<int, int> myMap = {{4, 40}, {5, 50}, {6, 60}};
    for_each(myMap.cbegin(), myMap.cend(), [](const pair<int, int>& p)
             {cout << p.first << "->" << p.second << endl;}); 
    return 0;
}
