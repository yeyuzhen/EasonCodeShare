#include "SpreadsheetCell.h"
#include <iostream>
using namespace std;

int main()
{
  SpreadsheetCell cell1;
  cell1.setValue(5.3);
  cout << cell1.getValue() << endl;

  return 0;
}
