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
	vector<int> vec1, vec2;

	populateContainer(vec1);

	vec2.resize(vec1.size());

	copy_backward(vec1.cbegin(), vec1.cend(), vec2.end());

	for_each(vec2.cbegin(), vec2.cend(), [](int i){cout << i << " ";});

	return 0;
}
