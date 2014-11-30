#include "Spreadsheet.h"

#include <iostream>
using namespace std;

class SpreadsheetApplication {};

int main()
{
  SpreadsheetApplication app;
  Spreadsheet s1(2, 3, app);
  Spreadsheet s2(3, 4, app);

  cout << "Maximum height is: " << Spreadsheet::kMaxHeight << endl;

  return 0;
}
