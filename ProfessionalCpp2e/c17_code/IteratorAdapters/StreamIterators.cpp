#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
	vector<int> myVector;
	for (int i = 0; i < 10; i++) {
		myVector.push_back(i);
	}

	// print the contents of the vector
	copy(myVector.begin(), myVector.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
