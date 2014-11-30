class SpreadsheetCell
{
 public:
  void setValue(double inValue);

 protected:
  double mValue;

 public:
  double getValue() const;
};
