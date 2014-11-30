#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// The list of elements to be searched
	vector<int> myVector = {5, 6, 9, 8, 8, 3}; 
	auto begin = myVector.begin();
	auto end = myVector.end();

	// Find the min and max elements in the vector
	auto it = min_element(begin, end);
	auto it2 = max_element(begin, end);
	cout << "min is " << *it << " and max is " << *it2 << endl;

	// Find the first pair of matching consecutive elements
	it = adjacent_find(begin, end);
	if (it != end) {
		cout << "Found two consecutive equal elements with value "
			<< *it << endl;
	}

	// Find the first of two values
	vector<int> targets = {8, 9};
	it = find_first_of(begin, end, targets.begin(), targets.end());
	if (it != end) {
		cout << "Found one of 8 or 9: " << *it << endl;
	}

	// Find the first subsequence
	vector<int> sub = {8, 3};
	it = search(begin, end, sub.begin(), sub.end());
	if (it != end) {
		cout << "Found subsequence {8,3}" << endl;
	} else {
		cout << "Unable to find subsequence {8,3}" << endl;
	}

	// Find the last subsequence (which is the same as the first in this example)
	it2 = find_end(begin, end, sub.begin(), sub.end());
	if (it != it2) {
		cout << "Error: search and find_end found different subsequences "
			<< "even though there is only one match." << endl;
	}

	// Find the first subsequence of two consecutive 8s
	it = search_n(begin, end, 2, 8);
	if (it != end) {
		cout << "Found two consecutive 8s" << endl;
	} else {
		cout << "Unable to find two consecutive 8s" << endl;
	}

	return 0;
}
