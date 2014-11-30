#include "GridZeroInitialized.h"

#include <iostream>
using namespace std;

template <typename T>
void printGrid(const Grid<T>& g)
{
	for (size_t i = 0; i < g.getWidth(); i++) {
		for (size_t j = 0; j < g.getHeight(); j++) {
			cout << g.getElementAt(i, j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	Grid<int> myIntGrid;
	Grid<int> myIntGrid2;
	Grid<int> myIntGrid3(myIntGrid);

	printGrid(myIntGrid);
	printGrid(myIntGrid2);

	myIntGrid = myIntGrid3;

	myIntGrid.setElementAt(3, 4, 5);
	cout << myIntGrid.getElementAt(3, 4) << endl;

	return 0;
}
