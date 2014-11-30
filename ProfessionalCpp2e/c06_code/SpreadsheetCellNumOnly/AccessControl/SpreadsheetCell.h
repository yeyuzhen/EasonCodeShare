// SpreadsheetCell.h
class SpreadsheetCell
{
  void setValue(double inValue);
 public:
  double getValue() const;

 protected:
  double mValue;
};
