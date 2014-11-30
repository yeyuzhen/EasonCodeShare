// GameBoard.cpp
#include "GameBoard.h"

using namespace std;

// Microsoft Visual Studio requires you to omit the following two lines.
// However, some compilers require them.
//const int GameBoard::kDefaultWidth;
//const int GameBoard::kDefaultHeight;

GameBoard::GameBoard(int inWidth, int inHeight) throw(bad_alloc) :
  mWidth(inWidth), mHeight(inHeight)
{
  int i = 0;
  mCells = new GamePiece* [mWidth];

  try {
    for (i = 0; i < mWidth; i++) {
      mCells[i] = new GamePiece[mHeight];
    }
  } catch (...) {
    // Cleanup any memory we already allocated, because the destructor
    // will never get called. The upper bound of the for loop is the
    // index of the last element in the mCells array that we tried
    // to allocate (the one that failed). All indices before that
    // one store pointers to allocated memory that must be freed.
    for (int j = 0; j < i; j++) { 
      delete [] mCells[j];
    }
    delete [] mCells;
    mCells = nullptr;

    // translate any exception to bad_alloc
    throw bad_alloc();
  }
}

GameBoard::GameBoard(const GameBoard& src) throw (bad_alloc)
{
  copyFrom(src);
}

GameBoard::~GameBoard() noexcept
{
  // free the old memory
  for (int i = 0; i < mWidth; i++) {
    delete [] mCells[i];
  }
  delete [] mCells;
  mCells = nullptr;
}

GameBoard& GameBoard::operator=(const GameBoard& rhs) throw (bad_alloc)
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

void GameBoard::copyFrom(const GameBoard& src) throw(bad_alloc)
{
  int i = 0;
  mWidth = src.mWidth;
  mHeight = src.mHeight;

  mCells = new GamePiece *[mWidth];

  try {
    for (i = 0; i < mWidth; i++) {
      mCells[i] = new GamePiece[mHeight];
    }
  } catch (...) {
    // Cleanup any memory we already allocated.
    // If this function is called from the copy constructor,
    // the destructor will never get called.
    // Use the same loop upper bound as described in the constructor.
    for (int j = 0; j < i; j++) {
      delete [] mCells[j];
    }
    delete [] mCells;

    // Set mCells and mWidth to values that will allow the
    // destructor to run without harming anything.
    // This function is called from operator=, in which case the
    // object was already constructed, so the destructor will get
    // called at some point.
    mCells = nullptr;
    mWidth = 0;
    throw bad_alloc();
  }

  for (i = 0; i < mWidth; i++) {
    for (int j = 0; j < mHeight; j++) {
      mCells[i][j] = src.mCells[i][j];
    }
  }
}

void GameBoard::setPieceAt(int x, int y, const GamePiece& inElem)
  throw(out_of_range)
{
  // Check for out of range arguments
  if (x < 0)
    throw out_of_range("GameBoard::setPieceAt: x-coordinate negative");
  if (x >= mWidth)
    throw out_of_range("GameBoard::setPieceAt: x-coordinate beyond width");
  if (y < 0)
    throw out_of_range("GameBoard::setPieceAt: y-coordinate negative");
  if (y >= mHeight)
    throw out_of_range("GameBoard::setPieceAt: y-coordinate beyond height");

  mCells[x][y] = inElem;
}

GamePiece& GameBoard::getPieceAt(int x, int y) throw(out_of_range)
{
  // Check for out of range arguments
  if (x < 0)
    throw out_of_range("GameBoard::getPieceAt: x-coordinate negative");
  if (x >= mWidth)
    throw out_of_range("GameBoard::getPieceAt: x-coordinate beyond width");
  if (y < 0)
    throw out_of_range("GameBoard::getPieceAt: y-coordinate negative");
  if (y >= mHeight)
    throw out_of_range("GameBoard::getPieceAt: y-coordinate beyond height");

  return mCells[x][y];
}

const GamePiece& GameBoard::getPieceAt(int x, int y) const throw(out_of_range)
{
  // Check for out of range arguments
  if (x < 0)
    throw out_of_range("GameBoard::getPieceAt const: x-coordinate negative");
  if (x >= mWidth)
    throw out_of_range("GameBoard::getPieceAt const: x-coordinate beyond width");
  if (y < 0)
    throw out_of_range("GameBoard::getPieceAt const: y-coordinate negative");
  if (y >= mHeight)
    throw out_of_range("GameBoard::getPieceAt const: y-coordinate beyond height");

  return mCells[x][y];
}
