#include <iostream>

using namespace std;

class Simple 
{
public:
	Simple() { cout << "Simple constructor called!" << endl; }
	virtual ~Simple() { cout << "Simple destructor called!" << endl; }
};

int main()
{
	Simple* mySimpleArray = new Simple[4];
	// Use mySimpleArray.
	delete [] mySimpleArray;
	mySimpleArray = nullptr;


	size_t arrSize = 4;
	Simple** mySimplePtrArray = new Simple*[arrSize];

	//  Allocate an object for each pointer.
	for (size_t i = 0; i < arrSize; i++) {
		mySimplePtrArray[i] = new Simple();
	}

	//  Use mySimplePtrArray.

	//  Delete each allocated object.
	for (size_t i = 0; i < arrSize; i++) {
		delete mySimplePtrArray[i];
	}

	//  Delete the array itself.
	delete [] mySimplePtrArray;
	mySimplePtrArray = nullptr;

	return 0;
}
