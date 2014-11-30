// SpreadsheetImpl.h
#include "SpreadsheetCell.h"

class SpreadsheetApplication; // forward declaration

class SpreadsheetImpl
{
 public:
  SpreadsheetImpl(const SpreadsheetApplication& theApp,
	      int inWidth = kMaxWidth, int inHeight = kMaxHeight);
  SpreadsheetImpl(const SpreadsheetImpl& src);
  ~SpreadsheetImpl();
  SpreadsheetImpl& operator=(const SpreadsheetImpl& rhs);

  void setCellAt(int x, int y, const SpreadsheetCell& cell);
  SpreadsheetCell getCellAt(int x, int y);

  int getId() const;

  // Initializing here doesn't work in some compilers
  static const int kMaxHeight = 100;
  static const int kMaxWidth = 100;

 protected:
  bool inRange(int val, int upper);
  void copyFrom(const SpreadsheetImpl& src);

  int mWidth, mHeight;
  int mId;
  SpreadsheetCell** mCells;

  const SpreadsheetApplication& mTheApp;

  static int sCounter;
}; 
