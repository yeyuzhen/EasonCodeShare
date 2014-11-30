#include <algorithm>
#include <functional>
#include <iterator>
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
	vector<int> vectorOne, vectorTwo;
	populateContainer(vectorOne);

	back_insert_iterator<vector<int>> inserter(vectorTwo);
	// With a C++11 lambda expression
	remove_copy_if(vectorOne.begin(), vectorOne.end(), inserter,
		[](int i){return i==100;});

	// Using Pre-C++11 bind2nd
	//remove_copy_if(vectorOne.begin(), vectorOne.end(), inserter,
	//	bind2nd(equal_to<int>(), 100));

	copy(vectorTwo.begin(), vectorTwo.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
