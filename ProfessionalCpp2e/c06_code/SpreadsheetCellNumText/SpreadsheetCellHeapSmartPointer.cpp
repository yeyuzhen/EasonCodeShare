#include "SpreadsheetCell.h"
#include <iostream>
#include <memory>
using namespace std;

int main()
{
  shared_ptr<SpreadsheetCell> myCellp(new SpreadsheetCell());
  myCellp->setValue(3.7);
  cout << "cell 1: " << myCellp->getValue() <<
    " " << myCellp->getString() << endl;

  return 0;
}
