#include "StringSpreadsheetCell.h"

using namespace std;

StringSpreadsheetCell::StringSpreadsheetCell() : mValue("#NOVALUE")
{
}

StringSpreadsheetCell::StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell)
{
	mValue = inDoubleCell.getString();
}

void StringSpreadsheetCell::set(const string& inString)
{
  mValue = inString;
}

string StringSpreadsheetCell::getString() const
{
  return mValue;
}
