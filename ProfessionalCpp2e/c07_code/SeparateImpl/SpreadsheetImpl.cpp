#include "SpreadsheetImpl.h"
#include <stdexcept>

int SpreadsheetImpl::sCounter = 0;

// Microsoft Visual Studio requires you to omit the following two lines.
// However, some compilers require them.
//const int SpreadsheetImpl::kMaxHeight;
//const int SpreadsheetImpl::kMaxWidth;

bool SpreadsheetImpl::inRange(int val, int upper)
{
  return (val >= 0 && val < upper);
}

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetApplication& theApp,
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

void SpreadsheetImpl::setCellAt(int x, int y, const SpreadsheetCell& cell)
{
  if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
    throw std::out_of_range("");
  }

  mCells[x][y] = cell;
}

SpreadsheetCell SpreadsheetImpl::getCellAt(int x, int y)
{
  if (!inRange(x, mWidth) || !inRange(y, mHeight)) {
    throw std::out_of_range("");
  }
  return mCells[x][y];
}

SpreadsheetImpl::~SpreadsheetImpl()
{
  for (int i = 0; i < mWidth; i++) {
    delete [] mCells[i];
  }
  delete [] mCells;
  mCells = nullptr;
}

void SpreadsheetImpl::copyFrom(const SpreadsheetImpl& src)
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

SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetImpl& src) :
  mTheApp(src.mTheApp)
{
  mId = sCounter++;
  copyFrom(src);
}

SpreadsheetImpl& SpreadsheetImpl::operator=(const SpreadsheetImpl& rhs)
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

int SpreadsheetImpl::getId() const
{
  return mId;
}
