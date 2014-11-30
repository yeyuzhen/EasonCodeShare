#include "SpreadsheetCell.h"

#include <iostream>
using namespace std;

int main()
{
  SpreadsheetCell myCell(4), anotherCell(5);
  SpreadsheetCell aThirdCell = myCell + anotherCell;

  string str = "hello";

  aThirdCell = myCell + str;
  aThirdCell = myCell + 5.6;
  aThirdCell = myCell + 4;

  aThirdCell = myCell + 4; // works fine
  aThirdCell = myCell + 5.6; // works fine

  // The following two lines don't compile
  // aThirdCell = 4 + myCell; // FAILS TO COMPILE!
  // aThirdCell = 5.6 + myCell; // FAILS TO COMPILE!

  return 0;
}
