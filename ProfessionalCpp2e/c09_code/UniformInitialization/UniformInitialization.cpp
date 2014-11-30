// UniformInitialization.cpp

#include <vector>
#include <string>

using namespace std;

struct CircleStruct
{
	int x, y;
	double radius;
};

class CircleClass
{
public:
	CircleClass(int x, int y, double radius)
		: mX(x), mY(y), mRadius(radius) {}
private:
	int mX, mY;
	double mRadius;
};

void func(int i) { /* ... */ }

class MyClass
{
public:
    MyClass() : mArray{0, 1, 2, 3} {}
private:
    int mArray[4];
};

int main()
{
	// Old pre-C++11 way
	CircleStruct myCircle1 = {10, 10, 2.5};
	CircleClass myCircle2(10, 10, 2.5);

	// New C++11 uniform initialization
	CircleStruct myCircle3 = {10, 10, 2.5};
	CircleClass myCircle4 = {10, 10, 2.5};
	CircleStruct myCircle5{10, 10, 2.5};
	CircleClass myCircle6{10, 10, 2.5};

	// Preventing narrowing
    //int x = {3.14};    // Error because narrowing
    //func({3.14});      // Error because narrowing

	// New method also works with vectors and maps
	vector<string> myVec = {"String 1", "String 2", "String 3"};

	// Can also be used with dynamic memory
	int* pArray = new int[4]{0, 1, 2, 3};

	// Create a MyClass object
	MyClass c;

	return 0;
}
