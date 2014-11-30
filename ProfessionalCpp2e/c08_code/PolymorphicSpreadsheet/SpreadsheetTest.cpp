#include <iostream>

#include "DoubleSpreadsheetCell.h"
#include "StringSpreadsheetCell.h"

using namespace std;

const StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
                                      const StringSpreadsheetCell& rhs)
{
    StringSpreadsheetCell newCell;
    newCell.set(lhs.getString() + rhs.getString());
    return newCell;
}

int main()
{
  SpreadsheetCell* cellArray[3];

  cellArray[0] = new StringSpreadsheetCell();
  cellArray[1] = new StringSpreadsheetCell();
  cellArray[2] = new DoubleSpreadsheetCell();

  cellArray[0]->set("hello");
  cellArray[1]->set("10");
  cellArray[2]->set("18");

  cout << "Array values are [" << cellArray[0]->getString() << "," <<
    cellArray[1]->getString() << "," <<
    cellArray[2]->getString() << "]" << endl; 

  DoubleSpreadsheetCell myDbl;
  myDbl.set(8.4);
  StringSpreadsheetCell result = myDbl + myDbl;
  cout << endl << result.getString() << endl;

  return 0;
}
