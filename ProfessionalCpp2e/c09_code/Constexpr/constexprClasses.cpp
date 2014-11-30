#include <iostream>

using namespace std;

class Rect
{
public:
    constexpr Rect(int width, int height) : mWidth(width), mHeight(height) {}
    constexpr int getArea() const { return mWidth * mHeight; }
private:
    int mWidth, mHeight;
};

int main()
{
	constexpr Rect r(8, 2);
	int myArray[r.getArea()];
	cout << sizeof(myArray) << endl;

	return 0;
}