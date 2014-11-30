#include "Grid.h"
#include "SpreadsheetCell.h"

int main()
{
	Grid<int, 0> myIntGrid;
	Grid<int, 10> myIntGrid2;

	SpreadsheetCell emptyCell;
	//Grid<SpreadsheetCell, emptyCell> mySpreadsheet; // WILL NOT COMPILE

	return 0;
}
