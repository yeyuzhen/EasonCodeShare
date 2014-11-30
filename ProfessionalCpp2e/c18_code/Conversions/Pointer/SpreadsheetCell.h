#include <string>
using std::string;

class SpreadsheetCell
{
 public:
  SpreadsheetCell();
  SpreadsheetCell(double initialValue);
  explicit SpreadsheetCell(const string& initialValue);
  SpreadsheetCell(const SpreadsheetCell& src);
  SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
  void set(double inValue);
  void set(const string& inString);

  double getValue() const {mNumAccesses++; return mValue; }
  string getString() const {mNumAccesses++; return mString; }

  static string doubleToString(double inValue);
  static double stringToDouble(const string& inString);

  friend const SpreadsheetCell operator+(const SpreadsheetCell& lhs,
					 const SpreadsheetCell& rhs);
  friend const SpreadsheetCell operator-(const SpreadsheetCell& lhs,
					 const SpreadsheetCell& rhs);
  friend const SpreadsheetCell operator*(const SpreadsheetCell& lhs,
					 const SpreadsheetCell& rhs);
  friend const SpreadsheetCell operator/(const SpreadsheetCell& lhs,
					 const SpreadsheetCell& rhs);
  SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
  SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
  SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
  SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);
  friend bool operator==(const SpreadsheetCell& lhs,
			 const SpreadsheetCell& rhs);
  friend bool operator<(const SpreadsheetCell& lhs,
			const SpreadsheetCell& rhs);
  friend bool operator>(const SpreadsheetCell& lhs,
			const SpreadsheetCell& rhs);
  friend bool operator!=(const SpreadsheetCell& lhs,
			 const SpreadsheetCell& rhs);
  friend bool operator<=(const SpreadsheetCell& lhs,
			 const SpreadsheetCell& rhs);
  friend bool operator>=(const SpreadsheetCell& lhs,
			 const SpreadsheetCell& rhs);
  const SpreadsheetCell operator-() const;
  SpreadsheetCell& operator++(); // prefix
  const SpreadsheetCell operator++(int); // postfix
  SpreadsheetCell& operator--(); // prefix 
  const SpreadsheetCell operator--(int); // postfix

  operator string() const;
  operator double() const;

 protected:
  double mValue;
  string mString;

  mutable int mNumAccesses;
};
