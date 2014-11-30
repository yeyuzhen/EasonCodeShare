#include "Grid.h"

#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	Grid<int, vector<int>> myIntGrid;
	Grid<int, deque<int>> myIntGrid2;

	myIntGrid.setElementAt(3, 4, 5);
	cout << myIntGrid.getElementAt(3, 4);

	Grid<int, vector<int>> grid2(myIntGrid);
	grid2 = myIntGrid;

	//Grid<int, int> test; // WILL NOT COMPILE

	return 0;
}
