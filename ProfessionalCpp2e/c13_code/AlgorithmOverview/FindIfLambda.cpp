#include <algorithm>
#include <vector>
#include <iostream>
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
	auto it = find_if(myVector.begin(), end, [](int i){ return i >= 100; });
	if (it == end) {
		cout << "No perfect scores" << endl;
	} else {
		cout << "Found a \"perfect\" score of " << *it << endl;
	}
	return 0;
}
