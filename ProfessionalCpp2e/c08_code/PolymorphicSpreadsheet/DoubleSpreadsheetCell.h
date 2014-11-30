#ifndef __DOUBLE_SPREADSHEET_CELL_H__
#define __DOUBLE_SPREADSHEET_CELL_H__

#include "SpreadsheetCell.h"

class DoubleSpreadsheetCell : public SpreadsheetCell
{
 public:
  DoubleSpreadsheetCell ();
  virtual void set(double inDouble);
  virtual void set(const std::string& inString);
    
  virtual std::string getString() const;

 protected:
  static std::string doubleToString(double inValue); 
  static double stringToDouble(const std::string& inValue);

  double mValue;
};

#endif