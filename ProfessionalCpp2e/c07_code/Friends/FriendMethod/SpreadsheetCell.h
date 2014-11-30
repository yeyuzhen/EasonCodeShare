#include <string>
#include "Spreadsheet.h"

using std::string;

class SpreadsheetCell
{
 public:
  friend void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell);
  SpreadsheetCell();
  SpreadsheetCell(double initialValue);
  SpreadsheetCell(const string& initialValue);
  SpreadsheetCell(const SpreadsheetCell &src);
  SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
  void setValue(double inValue);
  double getValue() const;
  void setString(const string& inString);
  string getString() const;

 protected:
  string doubleToString(double inValue) const;
  double stringToDouble(const string& inString) const;

  double mValue;
  string mString;
};
