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

  return 0;
}
