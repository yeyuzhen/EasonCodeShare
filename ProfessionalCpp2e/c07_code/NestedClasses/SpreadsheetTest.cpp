#include "Spreadsheet.h"

#include <iostream>
using namespace std;

class SpreadsheetApplication {};

int main()
{
  SpreadsheetApplication theApp;
  Spreadsheet s1(theApp);
  Spreadsheet s2(theApp, 5);
  Spreadsheet s3(theApp, 5, 6);

  Spreadsheet::SpreadsheetCell c1(4), c2(5);
  Spreadsheet::SpreadsheetCell c3(c1);
  c2 = c3;

  cout << c1.getValue() << endl;

  s2.getId();

  return 0;
}
