// Spreadsheet.h
#include "SpreadsheetCell.h"

class SpreadsheetApplication; // forward declaration

class Spreadsheet
{
 public:
  Spreadsheet(int inWidth, int inHeight,
	      const SpreadsheetApplication& theApp);
  Spreadsheet(const Spreadsheet& src);
  ~Spreadsheet();
  Spreadsheet& operator=(const Spreadsheet& rhs);

  void setCellAt(int x, int y, const SpreadsheetCell& cell);
  SpreadsheetCell getCellAt(int x, int y);

  int getId() const;

  // Doesn't work in Microsoft Visual Studio 6
  static const int kMaxHeight = 100;
  static const int kMaxWidth = 100;

 protected:
  bool inRange(int val, int upper);
  void copyFrom(const Spreadsheet& src);

  int mWidth, mHeight;
  int mId;
  SpreadsheetCell** mCells;

  const SpreadsheetApplication& mTheApp;

  static int sCounter = 0;
  //static int sCounter;	// Pre C++11
}; 
