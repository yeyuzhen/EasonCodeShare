#include "GridString.h"

#include <iostream>
using namespace std;

int main()
{
	Grid<int, 2, 2> myIntGrid;      // Uses the original Grid
	Grid<char*, 2, 2> myStringGrid; // Uses the partial specialization for char *s
	//  Grid<2, 3> test;            // DOES NOT COMPILE! No type specified.

	return 0;
}
