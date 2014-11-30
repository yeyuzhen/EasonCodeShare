#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

// Function template to populate a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true) {
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		cont.push_back(num);
	}
}

int main()
{
	vector<int> vec;
	populateContainer(vec);

	int lowerLimit = numeric_limits<short>::min();  // = -32768
	int upperLimit = numeric_limits<short>::max();  // = 32767

	replace_if(vec.begin(), vec.end(), [=](int i){return i < lowerLimit;}, lowerLimit);
	replace_if(vec.begin(), vec.end(), [=](int i){return i > upperLimit;}, upperLimit);

	for_each(vec.cbegin(), vec.cend(), [](int i){cout << i << " ";});
	cout << endl;

	return 0;
}
