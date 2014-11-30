#include <iostream>

using namespace std;

class IntWrapper
{
public:
	IntWrapper(int i) : mInt(i) {}
	//operator int() const { return mInt; }
	explicit operator int() const { return mInt; }
private:
	int mInt;
};
 
int main()
{
	IntWrapper c(123);

	//int iC1 = c;    // Error, because of explicit int() operator
	//cout << "iC1=" << iC1 << endl;

	int iC2 = int(c);
	cout << "iC2=" << iC2 << endl;

	int iC3 = static_cast<int>(c);
	cout << "iC3=" << iC3 << endl;

	return 0;
} 
