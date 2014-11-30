#include "Spreadsheet.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

int Spreadsheet::sCounter = 0;

// Microsoft Visual Studio requires you to omit the following two lines.
// However, some compilers require them.
//const int Spreadsheet::kMaxHeight;
//const int Spreadsheet::kMaxWidth;

bool Spreadsheet::inRange(int val, int upper)
{
  return (val >= 0 && val < upper);
}

Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp,
          int inWidth, int inHeight)
  : mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth),
    mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight), mTheApp(theApp)
{
  mId = sCounter++;
  mCells = new SpreadsheetCell* [mWidth];
  for (int i = 0; i < mWidth; i++) {
    mCells[i] = new SpreadsheetCell[mHeight];
  }
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
  if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
    throw std::out_of_range("");
  }

  mCells[x][y] = cell;
}
/*
Spreadsheet::SpreadsheetCell Spreadsheet::getCellAt(int x, int y)
{
  if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
    throw std::out_of_range("");
  }
  return mCells[x][y];
}
*/

SCell Spreadsheet::getCellAt(int x, int y)
{
  if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
    throw std::out_of_range("");
  }
  return mCells[x][y];
}

Spreadsheet::~Spreadsheet()
{
  for (int i = 0; i < mWidth; i++) {
    delete [] mCells[i];
  }
  delete [] mCells;
  mCells = nullptr;
}

void Spreadsheet::copyFrom(const Spreadsheet& src)
{
  mWidth = src.mWidth;
  mHeight = src.mHeight;

  mCells = new SpreadsheetCell* [mWidth];
  for (int i = 0; i < mWidth; i++) {
    mCells[i] = new SpreadsheetCell[mHeight];
  }

  for (int i = 0; i < mWidth; i++) {
    for (int j = 0; j < mHeight; j++) {
      mCells[i][j] = src.mCells[i][j];
    }
  }
}

Spreadsheet::Spreadsheet(const Spreadsheet& src) :
  mTheApp(src.mTheApp)
{
  mId = sCounter++;
  copyFrom(src);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
  // check for self-assignment
  if (this == &rhs) {
    return *this;
  }
  // free the old memory
  for (int i = 0; i < mWidth; i++) {
    delete [] mCells[i];
  }
  delete [] mCells;
  mCells = nullptr;

  // copy the new memory
  copyFrom(rhs);

  return *this;
}

int Spreadsheet::getId() const
{
  return mId;
}


SCell::SpreadsheetCell() : mValue(0), mNumAccesses(0)
{
}

SCell::SpreadsheetCell(double initialValue) : mNumAccesses(0)
{
  set(initialValue);
}

SCell::SpreadsheetCell(const string& initialValue) :
  mValue(stringToDouble(initialValue)), mString(initialValue), mNumAccesses(0)
{
}

SCell::SpreadsheetCell(const SpreadsheetCell& src)
{
  mValue = src.mValue;
  mString = src.mString;
  mNumAccesses = src.mNumAccesses;
}

SCell& SCell::operator=(const SpreadsheetCell& rhs)
{
  if (this == &rhs) {
    return *this;
  }
  mValue = rhs.mValue;
  mString = rhs.mString;
  mNumAccesses = rhs.mNumAccesses;
  return *this;
}

void SCell::set(double inValue)
{
  mValue = inValue;
  mString = doubleToString(mValue);
}

void SCell::set(const string& inString)
{
  mString = inString;
  mValue = stringToDouble(mString);
}

string SCell::doubleToString(double inValue)
{
  ostringstream ostr;

  ostr << inValue;
  return ostr.str();
}

double SCell::stringToDouble(const string& inString)
{
  double temp;

  istringstream istr(inString);

  istr >> temp;
  if (istr.fail() || !istr.eof()) {
    return 0;
  }
  return temp;
}


/*Spreadsheet::SpreadsheetCell::SpreadsheetCell() : mValue(0), mNumAccesses(0)
{
}

Spreadsheet::SpreadsheetCell::SpreadsheetCell(double initialValue) : mNumAccesses(0)
{
  set(initialValue);
}

Spreadsheet::SpreadsheetCell::SpreadsheetCell(const string& initialValue) :
  mValue(stringToDouble(initialValue)), mString(initialValue), mNumAccesses(0)
{
}

Spreadsheet::SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
{
  mValue = src.mValue;
  mString = src.mString;
  mNumAccesses = src.mNumAccesses;
}

Spreadsheet::SpreadsheetCell& Spreadsheet::SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
  if (this == &rhs) {
    return *this;
  }
  mValue = rhs.mValue;
  mString = rhs.mString;
  mNumAccesses = rhs.mNumAccesses;
  return *this;
}

void Spreadsheet::SpreadsheetCell::set(double inValue)
{
  mValue = inValue;
  mString = doubleToString(mValue);
}

void Spreadsheet::SpreadsheetCell::set(const string& inString)
{
  mString = inString;
  mValue = stringToDouble(mString);
}

string Spreadsheet::SpreadsheetCell::doubleToString(double inValue)
{
  ostringstream ostr;

  ostr << inValue;
  return ostr.str();
}

double Spreadsheet::SpreadsheetCell::stringToDouble(const string& inString)
{
  double temp;

  istringstream istr(inString);

  istr >> temp;
  if (istr.fail() || !istr.eof()) {
    return 0;
  }
  return temp;
}
*/