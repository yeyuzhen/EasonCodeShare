#include <iostream>
#include <vector>
#include "Spreadsheet.h"

using namespace std;

Spreadsheet CreateObject()
{
    return Spreadsheet(3, 2);
}

int main()
{
  vector<Spreadsheet> vec;
  for (int i = 0; i < 2; ++i) {
      cout << "Iteration " << i << endl;
      vec.push_back(Spreadsheet(100, 100));
      cout << endl;
  }

  Spreadsheet s(2,3);
  s = CreateObject();

  Spreadsheet s2(5,6);
  s2 = s;
  
  return 0;
}
