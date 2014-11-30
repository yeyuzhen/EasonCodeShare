// SpreadsheetCell.h

#ifndef __SPREADSHEET_CELL_H__
#define __SPREADSHEET_CELL_H__

#include <string>

class SpreadsheetCell
{
 public:
  SpreadsheetCell();
  virtual ~SpreadsheetCell();

  virtual void set(const std::string& inString) = 0;

  virtual std::string getString() const = 0;
};

#endif
