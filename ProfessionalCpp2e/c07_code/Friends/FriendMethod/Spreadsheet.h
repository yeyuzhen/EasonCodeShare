// Spreadsheet.h
#pragma once

class SpreadsheetCell;	// Forward declaration

class Spreadsheet
{
 public:
  Spreadsheet(int inWidth, int inHeight);
  Spreadsheet(const Spreadsheet& src);
  ~Spreadsheet();

  Spreadsheet& operator=(const Spreadsheet& rhs);

  void setCellAt(int x, int y, const SpreadsheetCell& cell);
  SpreadsheetCell getCellAt(int x, int y);

 protected:
  bool inRange(int val, int upper);
  void copyFrom(const Spreadsheet& src);

  int mWidth, mHeight;
  SpreadsheetCell** mCells;
};
