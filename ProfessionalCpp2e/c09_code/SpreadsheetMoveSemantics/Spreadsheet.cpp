#include <iostream>
#include "Spreadsheet.h"
#include <stdexcept>

using namespace std;

bool Spreadsheet::inRange(int val, int upper)
{
  return (val >= 0 && val < upper);
}

Spreadsheet::Spreadsheet(int inWidth, int inHeight) :
  mWidth(inWidth), mHeight(inHeight)
{
  cout << "Normal constructor" << endl;

  mCells = new SpreadsheetCell* [mWidth];
  for (int i = 0; i < mWidth; i++) {
    mCells[i] = new SpreadsheetCell[mHeight];
  }
}

Spreadsheet::Spreadsheet(const Spreadsheet &src)
{
  cout << "Copy constructor" << endl;
  copyFrom(src);
}

// Move constructor
Spreadsheet::Spreadsheet(Spreadsheet&& src)
{
  cout << "Move constructor" << endl;

  // Shallow copy of data
  mWidth = src.mWidth;
  mHeight = src.mHeight;
  mCells = src.mCells;
  // Reset the source object
  src.mWidth = 0;
  src.mHeight = 0;
  src.mCells = nullptr;
}

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
  if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
    throw std::out_of_range("");
  }

  mCells[x][y] = cell;
}

SpreadsheetCell Spreadsheet::getCellAt(int x, int y)
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

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
  cout << "Assignment operator" << endl;

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

// Move assignment operator
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs)
{
  cout << "Move assignment operator" << endl;

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

  // Shallow copy of data
  mWidth = rhs.mWidth;
  mHeight = rhs.mHeight;
  mCells = rhs.mCells;
  // Reset the source object
  rhs.mWidth = 0;
  rhs.mHeight = 0;
  rhs.mCells = nullptr;

  return *this;
}
