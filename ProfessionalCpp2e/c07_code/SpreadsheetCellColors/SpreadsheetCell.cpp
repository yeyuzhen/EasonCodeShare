#include "SpreadsheetCell.h"

#include <iostream>
#include <sstream>
using namespace std;

SpreadsheetCell::SpreadsheetCell() : mValue(0), mNumAccesses(0)
{
}

SpreadsheetCell::SpreadsheetCell(double initialValue) : mNumAccesses(0)
{
  set(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const string& initialValue) :
  mValue(stringToDouble(initialValue)), mString(initialValue), mNumAccesses(0)
{
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
{
  mValue = src.mValue;
  mString = src.mString;
  mNumAccesses = src.mNumAccesses;
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
  if (this == &rhs) {
    return *this;
  }
  mValue = rhs.mValue;
  mString = rhs.mString;
  mNumAccesses = rhs.mNumAccesses;
  return *this;
}

void SpreadsheetCell::set(double inValue)
{
  mValue = inValue;
  mString = doubleToString(mValue);
}

void SpreadsheetCell::set(const string& inString)
{
  mString = inString;
  mValue = stringToDouble(mString);
}

string SpreadsheetCell::doubleToString(double inValue)
{
  ostringstream ostr;

  ostr << inValue;
  return ostr.str();
}

double SpreadsheetCell::stringToDouble(const string& inString)
{
  double temp;

  istringstream istr(inString);

  istr >> temp;
  if (istr.fail() || !istr.eof()) {
    return 0;
  }
  return temp;
}

void SpreadsheetCell::setColor(Colors color)
{
	mColor = color;
}
