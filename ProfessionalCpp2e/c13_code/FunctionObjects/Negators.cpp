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
	
	// Using not1 and bind2nd
	auto it = find_if(myVector.begin(), end,
		not1(bind2nd(greater_equal<int>(), 100)));

	// Using C++11 Lambda:
	//auto it = find_if(myVector.begin(), end, [](int i){ return i < 100; });

	if (it == end) {
		cout << "All perfect scores" << endl;
	} else {
		cout << "Found a \"less-than-perfect\" score of " << *it << endl;
	}

	return 0;
}
