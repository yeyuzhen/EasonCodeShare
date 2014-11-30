#include <algorithm>
#include <vector>
#include <iostream>
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
	vector<int> vectorOne, vectorTwo, vectorMerged;
	cout << "Enter values for first vector:" << endl;
	populateContainer(vectorOne);
	cout << "Enter values for second vector:" << endl;
	populateContainer(vectorTwo);

	// Sort both containers
	sort(vectorOne.begin(), vectorOne.end());
	sort(vectorTwo.begin(), vectorTwo.end());
	// make sure the destination vector is large enough to hold the values
	// from both source vectors
	vectorMerged.resize(vectorOne.size() + vectorTwo.size());
	merge(vectorOne.cbegin(), vectorOne.cend(), vectorTwo.cbegin(),
		vectorTwo.cend(), vectorMerged.begin());

	cout << "Merged vector: ";
	for_each(vectorMerged.cbegin(), vectorMerged.cend(), [](int i){cout << i << " ";});
	cout << endl;

	while (true) {
		int num;
		cout << "Enter a number to find (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		if (binary_search(vectorMerged.cbegin(), vectorMerged.cend(), num)) {
			cout << "That number is in the vector." << endl;
		} else {
			cout << "That number is not in the vector." << endl;
		}
	}

	return 0;
}
