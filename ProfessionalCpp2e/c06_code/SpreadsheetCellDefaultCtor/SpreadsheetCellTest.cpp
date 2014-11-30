#include "SpreadsheetCell.h"
#include <iostream>
using namespace std;

int main()
{
  SpreadsheetCell myCell;
  myCell.setValue(6);
  cout << "cell 1: " << myCell.getValue() << endl;

  // Note the function-call syntax
  SpreadsheetCell* myCellp = new SpreadsheetCell();
      
  return 0;
}
