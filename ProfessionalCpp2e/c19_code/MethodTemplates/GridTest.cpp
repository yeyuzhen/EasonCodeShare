#include "Grid.h"

int main()
{
	Grid<int> myIntGrid;
	Grid<double> myDoubleGrid;

	myDoubleGrid = myIntGrid;
	Grid<double> newDoubleGrid(myIntGrid);

	return 0;
}
