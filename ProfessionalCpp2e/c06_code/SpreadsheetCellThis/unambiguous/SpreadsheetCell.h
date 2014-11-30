#include <string>
using std::string;

class SpreadsheetCell
{
 public:
  void setValue(double value);
  double getValue() const;
  void setString(string inString);
  string getString() const;

 protected:
  string doubleToString(double inValue) const;
  double stringToDouble(string inString) const;

  double value;
  string mString;
};
