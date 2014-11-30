#include "AssociativeArray.h"
#include <iostream>

using namespace std;

int main()
{
	AssociativeArray myArray;
	myArray["Key 1"] = 11;
	myArray["Key 2"] = 22;
	myArray["Key 3"] = 33;
	
	try {
		cout << myArray["Key 1"] << endl;
		cout << myArray["Key 2"] << endl;

		// Test const operator[]
		const AssociativeArray& c = myArray;
		cout << c["Key 3"] << endl;
		cout << c["Key 4"] << endl;
	} catch (const invalid_argument& ex) {
		cout << "Caught exception: " << ex.what() << endl;
	}

	return 0;
}
