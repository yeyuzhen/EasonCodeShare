// SpreadsheetCell.h
class SpreadsheetCell
{
 public:
  void setValue(double inValue);
  double getValue() const;

 protected:
  double mValue;
};
