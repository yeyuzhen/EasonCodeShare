#include <iostream>
#include <stdexcept>

using namespace std;

class MyArray
{
public:
	MyArray(size_t size);
	virtual ~MyArray();
	size_t getSize() const;
	int& at(size_t index) throw(out_of_range);

protected:
	size_t mSize;
	int* mArray;
};

MyArray::MyArray(size_t size) : mSize(size), mArray(nullptr)
{
	mArray = new int[size];
}

MyArray::~MyArray()
{
	if (mArray) {
		delete [] mArray;
		mArray = nullptr;
	}
}

size_t MyArray::getSize() const
{
	return mSize;
}

int& MyArray::at(size_t index) throw(out_of_range)
{
	if (index >= 0 && index < getSize())
		return mArray[index];
	else
		throw out_of_range("MyArray::at: Index out of range.");
}

int main()
{
	MyArray arr(10);
	cout << "Array size: " << arr.getSize() << endl;

	arr.at(3) = 42;
	cout << "arr[3] = " << arr.at(3) << endl;

	try {
		arr.at(10) = 3;
	} catch (const exception& e) {
		cout << "Caught exception: '" << e.what() << "'" << endl;
	}

	return 0;
}
