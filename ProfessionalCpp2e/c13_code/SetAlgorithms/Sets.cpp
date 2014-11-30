#include <algorithm>
#include <iostream>
#include <vector>
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
	vector<int> vec1, vec2, result;
	cout << "Enter elements for set 1:" << endl;
	populateContainer(vec1);
	cout << "Enter elements for set 2:" << endl;
	populateContainer(vec2);

	// set algorithms work on sorted ranges
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	cout << "Set 1: ";
	for_each(vec1.cbegin(), vec1.cend(), [](int i){cout << i << " ";});
	cout << endl;
	cout << "Set 2: ";
	for_each(vec2.cbegin(), vec2.cend(), [](int i){cout << i << " ";});
	cout << endl;


	if (includes(vec1.cbegin(), vec1.cend(), vec2.cbegin(), vec2.cend())) {
		cout << "The second set is a subset of the first." << endl;
	}
	if (includes(vec2.cbegin(), vec2.cend(), vec1.cbegin(), vec1.cend())) {
		cout << "The first set is a subset of the second" << endl;
	}

	result.resize(vec1.size() + vec2.size());
	auto newEnd = set_union(vec1.cbegin(), vec1.cend(), vec2.cbegin(),
		vec2.cend(), result.begin());
	cout << "The union is: ";
	for_each(result.begin(), newEnd, [](int i){cout << i << " ";});
	cout << endl;

	newEnd = set_intersection(vec1.cbegin(), vec1.cend(), vec2.cbegin(),
		vec2.cend(), result.begin());
	cout << "The intersection is: ";
	for_each(result.begin(), newEnd, [](int i){cout << i << " ";});
	cout << endl;

	newEnd = set_difference(vec1.cbegin(), vec1.cend(), vec2.cbegin(),
		vec2.cend(), result.begin());
	cout << "The difference between set 1 and set 2 is: ";
	for_each(result.begin(), newEnd, [](int i){cout << i << " ";});
	cout << endl;

	newEnd = set_symmetric_difference(vec1.cbegin(), vec1.cend(), vec2.cbegin(),
		vec2.cend(), result.begin());
	cout << "The symmetric difference is: ";
	for_each(result.begin(), newEnd, [](int i){cout << i << " ";});
	cout << endl;

	return 0;
}
