#include "SpreadsheetCell.h"
#include <iostream>
using namespace std;

int main()
{
  SpreadsheetCell myCell;
  string name = "heading one";
  myCell.setString(name); // copies name

  SpreadsheetCell myCell2(4);
  SpreadsheetCell myCell3(myCell2);
  // myCell3 now has the values of myCell2

  return 0;
}
