// Spreadsheet.h
#include <string>
using std::string;

class SpreadsheetApplication; // forward declaration

class Spreadsheet
{
 public:

  class SpreadsheetCell
    {
    public:
      SpreadsheetCell();
      SpreadsheetCell(double initialValue);
      SpreadsheetCell(const string& initialValue);
      SpreadsheetCell(const SpreadsheetCell& src);
      SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
      void set(double inValue);
      void set(const string& inString);

      double getValue() const {mNumAccesses++; return (mValue); }
      string getString() const {mNumAccesses++; return (mString); }

      static string doubleToString(double inValue);
      static double stringToDouble(const string& inString);

    protected:
      double mValue;
      string mString;

      mutable int mNumAccesses;
    };

  Spreadsheet(const SpreadsheetApplication& theApp,
          int inWidth = kMaxWidth, int inHeight = kMaxHeight);
  Spreadsheet(const Spreadsheet& src);
  ~Spreadsheet();
  Spreadsheet& operator=(const Spreadsheet& rhs);

  void setCellAt(int x, int y, const SpreadsheetCell& cell);
  SpreadsheetCell getCellAt(int x, int y);

  int getId() const;

  // Initializing here doesn't work in some compilers
  static const int kMaxHeight = 100;
  static const int kMaxWidth = 100;

 protected:
  bool inRange(int val, int upper);
  void copyFrom(const Spreadsheet& src);

  int mWidth, mHeight;
  int mId;
  SpreadsheetCell** mCells;

  const SpreadsheetApplication& mTheApp;

  static int sCounter;
}; 

typedef Spreadsheet::SpreadsheetCell SCell;
