#include "Array.h"

#include <stdexcept>
using namespace std;

// Microsoft Visual Studio requires you to omit the following line.
// However, some compilers require it.
//const size_t Array::kAllocSize;

Array::Array()
{
	mSize = kAllocSize;
	mElems = new int[mSize];
	initializeElements();
}

Array::~Array()
{
	delete [] mElems;
	mElems = nullptr;
}

void Array::initializeElements()
{
	for (size_t i = 0; i < mSize; i++)
		mElems[i] = 0;
}

void Array::resize(size_t newSize)
{
	// Make a copy of the current elements pointer and size
	int* oldElems = mElems;
	size_t oldSize = mSize;
	// Create new bigger array
	mSize = newSize;           // store the new size
	mElems = new int[newSize]; // Allocate the new array of the new size
	initializeElements();      // Initialize all elements to 0

	// The new size is always bigger than the old size
	for (size_t i = 0; i < oldSize; i++) {
		// Copy the elements from the old array to the new one
		mElems[i] = oldElems[i];
	}

	delete [] oldElems; // free the memory for the old array
}

int& Array::operator[](size_t x)
{
	if (x < 0) {
		throw out_of_range("");
	}
	if (x >= mSize) {
		// Allocate kAllocSize past the element the client wants
		resize(x + kAllocSize);
	}
	return mElems[x];
}

const int& Array::operator[](size_t x) const
{
	if (x < 0 || x >= mSize) {
		throw out_of_range("");
	}
	return mElems[x];
}

//int Array::getElementAt(size_t x) const
//{
//    if (x < 0 || x >= mSize) {
//        throw out_of_range("");
//    }
//    return mElems[x];
//}
//void Array::setElementAt(size_t x, int val)
//{
//    if (x < 0) {
//        throw out_of_range("");
//    }
//    if (x >= mSize) {
//        // Allocate kAllocSize past the element the client wants
//        resize(x + kAllocSize);
//    }
//    mElems[x] = val;
//}
