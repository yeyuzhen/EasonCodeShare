#include <iostream>
using namespace std;

#include "GridPtr.h"

int main()
{
	Grid<int> myIntGrid;     // Uses the non-specialized grid
	Grid<int*> psGrid(2, 2); // Uses the partial specialization for pointer types

	int x = 3, y = 4;
	psGrid.setElementAt(0, 0, &x);
	psGrid.setElementAt(0, 1, &y);
	psGrid.setElementAt(1, 0, &y);
	psGrid.setElementAt(1, 1, &x);

	Grid<int*> psGrid2(psGrid);
	Grid<int*> psGrid3;
	psGrid3 = psGrid2;

	const Grid<int*>& psGrid4 = psGrid2;
	cout << *(psGrid4.getElementAt(1, 1)) << endl;
	x=6;
	cout << *(psGrid4.getElementAt(1, 1)) << endl;

	return 0;
}
