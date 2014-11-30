#include "Grid.h"
#include "SpreadsheetCell.h"

#include <string>
#include <vector>
using namespace std;

void processIntGrid(Grid<int>& inGrid)
{
	// body omitted for brevity
}

int main()
{
	Grid<int> myIntGrid; // declares a grid that stores ints
	myIntGrid.setElementAt(0, 0, 10);
	int x = myIntGrid.getElementAt(0, 0);

	Grid<int> grid2(myIntGrid);
	Grid<int> anotherIntGrid = grid2;

	//Grid test; // WILL NOT COMPILE
	//Grid<> test; // WILL NOT COMPILE

	Grid<SpreadsheetCell> mySpreadsheet;
	SpreadsheetCell myCell;
	mySpreadsheet.setElementAt(3, 4, myCell);

	Grid<char*> myStringGrid;
	myStringGrid.setElementAt(2, 2, "hello");

	Grid<vector<int>> gridOfVectors;
	vector<int> myVector;
	gridOfVectors.setElementAt(5, 6, myVector);

	Grid<int>* myGridp = new Grid<int>();
	myGridp->setElementAt(0, 0, 10);
	x = myGridp->getElementAt(0, 0);
	delete myGridp;

	return 0;
}
