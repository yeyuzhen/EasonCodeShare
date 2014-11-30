#include "Spreadsheet.h"
#include "SpreadsheetImpl.h"

void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& inCell)
{
  mImpl->setCellAt(x, y, inCell);
}

SpreadsheetCell Spreadsheet::getCellAt(int x, int y)
{
  return mImpl->getCellAt(x, y);
}

int Spreadsheet::getId() const
{
  return mImpl->getId();
}

Spreadsheet::Spreadsheet(const SpreadsheetApplication &theApp, int inWidth,
			 int inHeight) 
{
  mImpl = new SpreadsheetImpl(theApp, inWidth, inHeight);
}

Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp) 
{
  mImpl = new SpreadsheetImpl(theApp);
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
{
  mImpl = new SpreadsheetImpl(*(src.mImpl));
}

Spreadsheet::~Spreadsheet()
{
  delete mImpl;
  mImpl = nullptr;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
  *mImpl = *(rhs.mImpl);
  return *this;
}
