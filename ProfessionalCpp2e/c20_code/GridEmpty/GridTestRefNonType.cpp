#include "GridRefNonType.h"
#include "SpreadsheetCell.h"

extern const int emptyInt = 0;
extern const SpreadsheetCell emptyCell(0);

int main()
{
	// The following line causes an internal compiler error with
	// g++ 3.2.2 on Linux and g++ 3.4.1 on Solaris 9. It compiles
	// without errors with g++ 4.6 on Linux and MS VC++ 2010.
	Grid<int, emptyInt> myIntGrid;
	Grid<SpreadsheetCell, emptyCell> mySpreadsheet;

	Grid<int, emptyInt> myIntGrid2(myIntGrid);

	return 0;
}
