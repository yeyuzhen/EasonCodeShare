#include "Array.h"
#include <iostream>

using namespace std;

void printArray(const Array& arr, size_t size);

int main()
{
	Array myArray;
	for (size_t i = 0; i < 10; i++) {
		myArray[i] = 100; // Calls the non-const operator[] because
		                  // myArray is a non-const object.
	}
	printArray(myArray, 10);

	//Array myArray;
	//for (size_t i = 0; i < 10; i++) {
	//	myArray.setElementAt(i, 100);
	//}
	//for (size_t i = 0; i < 10; i++) {
	//	cout << myArray.getElementAt(i) << " ";
	//}

	return 0;
}

void printArray(const Array& arr, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " "; // calls the const operator[] because arr is a const
		                       // object.
	}
	cout << endl;
}
