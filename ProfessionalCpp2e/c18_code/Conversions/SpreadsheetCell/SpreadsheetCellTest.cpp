#include "SpreadsheetCell.h"

#include <iostream>
using namespace std;

int main()
{
	SpreadsheetCell cell(1.23);
	string str = cell; // Works as expected
	double d1 = cell;

	//  double d2 = cell + 3.3; // DOES NOT COMPILE IF YOU DEFINE operator double()

	// C++11 explicit operator double() demonstration
	//SpreadsheetCell cell = 6.6;
	//string str = cell;
	//double d1 = static_cast<double>(cell);
	//double d2 = static_cast<double>(cell + 3.3);


	return 0;
}
