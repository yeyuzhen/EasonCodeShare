#include "PointerBool.h"
#include "SpreadsheetCell.h"

#include <iostream>
using namespace std;

void process(Pointer<SpreadsheetCell>& p)
{
	//if (p != nullptr) { cout << "not nullptr" << endl; }	// Error
	if (p != NULL) { cout << "not NULL" << endl; }
	if (p) { cout << "not nullptr" << endl; }
	if (!p) { cout << "nullptr" << endl; }
}

int main()
{
	Pointer<SpreadsheetCell> smartCell(nullptr);
	process(smartCell);
	cout << endl;
	Pointer<SpreadsheetCell> anotherSmartCell(new SpreadsheetCell(5.0));
	process(anotherSmartCell);

	return 0;
} 
