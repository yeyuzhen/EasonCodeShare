#include "Spreadsheet.h"
#include <stdexcept>

bool Spreadsheet::inRange(int val, int upper)
{
  return (val >= 0 && val < upper);
}

Spreadsheet::Spreadsheet(int inWidth, int inHeight) :
  mWidth(inWidth), mHeight(inHeight)
{
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

Spreadsheet::Spreadsheet(const Spreadsheet& src)
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
  mWidth = rhs.mWidth;
  mHeight = rhs.mHeight;

  mCells = new SpreadsheetCell* [mWidth];
  for (int i = 0; i < mWidth; i++) {
    mCells[i] = new SpreadsheetCell[mHeight];
  }

  for (int i = 0; i < mWidth; i++) {
    for (int j = 0; j < mHeight; j++) {
      mCells[i][j] = rhs.mCells[i][j];
    }
  }
  return *this;
}
