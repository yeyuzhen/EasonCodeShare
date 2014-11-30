#include "SpreadsheetCell.h"

#include <iostream>
using namespace std;

int main()
{
  SpreadsheetCell c1(4);
  if (checkSpreadsheetCell(c1)) {
    cout << "PASS\n";
  } else {
    cout << "FAIL\n";
  }

  return 0;
}
