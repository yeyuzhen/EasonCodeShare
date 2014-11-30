#include <string>
using std::string;

class SpreadsheetCell
{
 public:
  SpreadsheetCell();
  SpreadsheetCell(double initialValue);
  SpreadsheetCell(const string& initialValue);
  //explicit SpreadsheetCell(const string& initialValue);
  SpreadsheetCell(const SpreadsheetCell& src);
  SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
  void set(double inValue);
  void set(const string& inString);

  double getValue() const {mNumAccesses++; return (mValue); }
  string getString() const {mNumAccesses++; return (mString); }

  static string doubleToString(double inValue);
  static double stringToDouble(const string& inString);

  const SpreadsheetCell operator+(const SpreadsheetCell& cell) const;
  //const SpreadsheetCell operator+(double rhs) const;

 protected:
  double mValue;
  string mString;

  mutable int mNumAccesses;
};
