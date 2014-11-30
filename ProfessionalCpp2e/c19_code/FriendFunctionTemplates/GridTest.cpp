#include "Grid.h"

int main()
{
	Grid<int> grid;
	grid.setElementAt(2, 3, 1);

	// Note that most elements printed by the line below will contain
	// garbage because only element (2, 3) is set to a specific value
	// and this implementation of the Grid template does not
	// zero-initialize elements.
	std::cout << grid;

	return 0;
}
