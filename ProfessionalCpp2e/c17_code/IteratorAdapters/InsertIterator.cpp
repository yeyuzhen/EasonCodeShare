#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <iostream>
#include <set>

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
	vector<int> vectorOne;
	set<int> setOne;
	populateContainer(vectorOne);

	insert_iterator<set<int>> inserter(setOne, setOne.begin());
	remove_copy_if(vectorOne.begin(), vectorOne.end(), inserter,
		[](int i){return i==100;});

	copy(setOne.begin(), setOne.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	return 0;
}
