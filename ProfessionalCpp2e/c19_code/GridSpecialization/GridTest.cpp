#include <iostream>
#include <string>
using namespace std;

#include "GridString.h"

int main()
{
	Grid<int> myIntGrid;           // Uses original Grid template
	Grid<char*> stringGrid1(2, 2); // Uses char* specialization

	string dummy = "dummy";
	stringGrid1.setElementAt(0, 0, "hello");
	stringGrid1.setElementAt(0, 1, dummy.c_str());
	stringGrid1.setElementAt(1, 0, dummy.c_str());
	stringGrid1.setElementAt(1, 1, "there");

	Grid<char*> stringGrid2(stringGrid1);

	cout << stringGrid2.getElementAt(0, 1) << endl;

	return 0;
}
