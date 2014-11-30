#include <iostream>
#include <limits>

using namespace std;

int main()
{
	cout << "Max int value: " << numeric_limits<int>::max() << endl;
	cout << "Lowest int value: " << numeric_limits<int>::lowest() << endl;

	cout << "Max double value: " << numeric_limits<double>::max() << endl;
	cout << "Lowest double value: " << numeric_limits<double>::lowest() << endl;

	return 0;
}