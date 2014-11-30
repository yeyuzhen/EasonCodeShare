#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
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
	vector<int> myVector;
	populateContainer(myVector);

	int num;
	cout << "Enter a number to find: ";
	cin >> num;

	//vector<int>::iterator it1;
	//vector<int>::reverse_iterator it2;
	//it1 = find(myVector.begin(), myVector.end(), num);
	//it2 = find(myVector.rbegin(), myVector.rend(), num);
	auto it1 = find(myVector.begin(), myVector.end(), num);
	auto it2 = find(myVector.rbegin(), myVector.rend(), num);

	if (it1 != myVector.end()) {
		cout << "Found " << num << " at position " << it1 - myVector.begin()
			<< " going forward." << endl;
		cout << "Found " << num << " at position "
			<< it2.base() - 1 - myVector.begin() << " going backward." << endl;
	} else {
		cout << "Failed to find " << num << endl;
	}

	return 0;
}
