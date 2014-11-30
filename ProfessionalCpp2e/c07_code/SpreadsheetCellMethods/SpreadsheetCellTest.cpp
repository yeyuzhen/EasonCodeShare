#include "SpreadsheetCell.h"
#include <iostream>
using namespace std;

int main()
{
  string str = SpreadsheetCell::doubleToString(5);

  SpreadsheetCell myCell(5);

  cout << myCell.getValue() << endl; // OK
  myCell.set("6"); // OK

  const SpreadsheetCell& anotherCell = myCell;

  cout << anotherCell.getValue() << endl; // OK
  //anotherCell.set("6"); // Compilation Error!

  return 0;
}
