#include "SpreadsheetCell.h"

// forward declarations
class SpreadsheetImpl;
class SpreadsheetApplication;

class Spreadsheet
{
 public:

  Spreadsheet(const SpreadsheetApplication& theApp, int inWidth,
	      int inHeight);
  Spreadsheet(const SpreadsheetApplication& theApp);
  Spreadsheet(const Spreadsheet& src);
  ~Spreadsheet();
  Spreadsheet& operator=(const Spreadsheet& rhs);
  void setCellAt(int x, int y, const SpreadsheetCell& inCell);
  SpreadsheetCell getCellAt(int x, int y);
  int getId() const;

 protected:
  SpreadsheetImpl* mImpl;
};
