#include "GridTemplateTemplate.h"

#include <vector>
using namespace std;

int main()
{
	Grid<int, vector> myGrid;

	myGrid.setElementAt(1, 2, 3);
	myGrid.getElementAt(1, 2);
	Grid<int, vector> myGrid2(myGrid);

	return 0;
}
