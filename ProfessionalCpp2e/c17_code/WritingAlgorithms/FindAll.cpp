#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename InputIterator, typename Predicate>
vector<InputIterator>
	find_all(InputIterator first, InputIterator last, Predicate pred)
{
	vector<InputIterator> res;

	while (true) {
		// find the next match in the current range
		first = find_if(first, last, pred);
		// check if find_if failed to find a match
		if (first == last) {
			break;
		}
		// store this match
		res.push_back(first);
		// shorten the range to start at one past the current match
		++first;
	}
	return res;
}

int main()
{
	vector<int> vec = {3, 4, 5, 4, 5, 6, 5, 8};
	auto all = find_all(vec.begin(), vec.end(), [](int i){return i==5;});

	cout << "Found " << all.size() << " matching elements: ";

	for (auto it : all) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
