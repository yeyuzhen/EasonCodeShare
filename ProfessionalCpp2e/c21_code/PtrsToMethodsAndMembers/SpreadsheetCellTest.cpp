#include "SpreadsheetCell.h"
#include <iostream>
using namespace std;

int main()
{
	SpreadsheetCell myCell(123);
	//double (SpreadsheetCell::*methodPtr) () const = &SpreadsheetCell::getValue;
	typedef double (SpreadsheetCell::*PtrToGet) () const;
	PtrToGet methodPtr = &SpreadsheetCell::getValue;
	cout << (myCell.*methodPtr)() << endl;

	return 0;
}
