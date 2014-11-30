#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

int main()
{
	int num;

	vector<int> myVector;
	while (true) {
		cout << "Enter a test score to add (0 to stop): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		myVector.push_back(num);
	}

	auto end = myVector.end();
	
	// C++11 solution using std::bind
	auto it = find_if(myVector.begin(), end,
		bind(greater_equal<int>(), placeholders::_1, 100));

	// Pre-C++11 solution using bind2nd
	//vector<int>::iterator it = find_if(myVector.begin(), end,
	//                  bind2nd(greater_equal<int>(), 100));

	// Recommended C++11 solution with lambda
	//auto it = find_if(myVector.begin(), end, [](int i){ return i >= 100; });

	if (it == end) {
		cout << "No perfect scores" << endl;
	} else {
		cout << "Found a \"perfect\" score of " << *it << endl;
	}
	return 0;
}
