#include "Grid.h"

#include <iostream>
using namespace std;

int main()
{
	Grid<int, 10, 10> myGrid;
	Grid<int, 10, 10> anotherGrid;

	myGrid.setElementAt(2, 3, 45);
	anotherGrid = myGrid;

	cout << anotherGrid.getElementAt(2, 3);

	return 0;
}
