#include "SpreadsheetCell.h"

#include <iostream>
#include <sstream>
using namespace std;

SpreadsheetCell::SpreadsheetCell()
{
  mValue = 0;
  mString = "";
}

SpreadsheetCell::SpreadsheetCell(double initialValue)
{
  setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(string initialValue)
{
  setString(initialValue);
}

void SpreadsheetCell::setValue(double inValue)
{
  mValue = inValue;
  mString = doubleToString(mValue);
}

double SpreadsheetCell::getValue() const
{
  return mValue;
}

void SpreadsheetCell::setString(string inString)
{
  mString = inString;
  mValue = stringToDouble(mString);
}

string SpreadsheetCell::getString() const
{
  return mString;
}

string SpreadsheetCell::doubleToString(double inValue) const
{
  ostringstream ostr;

  ostr << inValue;
  return ostr.str();
}

double SpreadsheetCell::stringToDouble(string inString) const
{
  double temp;

  istringstream istr(inString);

  istr >> temp;
  if (istr.fail() || !istr.eof()) {
    return 0;
  }
  return temp;
}
