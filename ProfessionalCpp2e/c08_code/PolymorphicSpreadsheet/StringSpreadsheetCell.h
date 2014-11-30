#ifndef __STRING_SPREADSHEET_CELL_H__
#define __STRING_SPREADSHEET_CELL_H__

#include "SpreadsheetCell.h"
#include "DoubleSpreadsheetCell.h"

class StringSpreadsheetCell : public SpreadsheetCell
{
 public:
  StringSpreadsheetCell();
  StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell);

  virtual void set(const std::string& inString);
    
  virtual std::string getString() const;

 protected:
  std::string mValue;
};

#endif