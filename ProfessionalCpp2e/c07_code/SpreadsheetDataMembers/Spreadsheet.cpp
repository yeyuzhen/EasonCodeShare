#include "Spreadsheet.h"
#include <stdexcept>

//int Spreadsheet::sCounter = 0;	// Pre C++11

// Microsoft Visual Studio requires you to omit the following two lines.
// However, some compilers require them.
//const int Spreadsheet::kMaxHeight;
//const int Spreadsheet::kMaxWidth;

bool Spreadsheet::inRange(int val, int upper)
{
  return (val >= 0 && val < upper);
}

#include <iostream>
using namespace std;

Spreadsheet::Spreadsheet(int inWidth, int inHeight,
             const SpreadsheetApplication& theApp)
  : mWidth(inWidth < kMaxWidth ? inWidth : kMaxWidth),
    mHeight(inHeight < kMaxHeight ? inHeight : kMaxHeight), mTheApp(theApp)
{
  mId = sCounter++;
  cout << mId << endl;
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
