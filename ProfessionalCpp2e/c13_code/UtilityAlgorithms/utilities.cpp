#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
  int x = 4, y = 5;
  cout << "x is " << x << " and y is " << y << endl;
  cout << "Max is " << max(x, y) << endl;
  cout << "Min is " << min(x, y) << endl;
  swap(x, y);
  cout << "x is " << x << " and y is " << y << endl;
  cout << "Max is " << max(x, y) << endl;
  cout << "Min is " << min(x, y) << endl;

  // C++11: using max and min on more than two values
  int x1 = 2, x2 = 9, x3 = 3, x4 = 12;
  cout << "Max of 4 elements is " << max({x1,x2,x3,x4}) << endl;
  cout << "Min of 4 elements is " << min({x1,x2,x3,x4}) << endl;
  // C++11: using minmax
  auto p2 = minmax({x1,x2,x3,x4});
  cout << "Minmax of 4 elements is <"
       << p2.first << "," << p2.second << ">" << endl;
  // C++11: using minmax without auto
  pair<int,int> p1 = minmax({x1,x2,x3,x4});
  cout << "Minmax of 4 elements is <"
       << p1.first << "," << p1.second << ">" << endl;

  return 0;
}
