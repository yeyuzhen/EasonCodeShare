#include "SpreadsheetCell.h"

#include <iostream>
#include <sstream>
using namespace std;

void SpreadsheetCell::setValue(double value)
{
  value = value; // Ambiguous!
  mString = doubleToString(value);
}

double SpreadsheetCell::getValue() const
{
  return value;
}

void SpreadsheetCell::setString(string inString)
{
  mString = inString;
  value = stringToDouble(mString);
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
