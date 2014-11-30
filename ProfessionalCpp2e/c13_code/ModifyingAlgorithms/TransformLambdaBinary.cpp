#include <algorithm>
#include <functional>
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

void print(int elem)
{
	cout << elem << " ";
}

int main()
{
	vector<int> vec1;
	cout << "Vector1:" << endl;
	populateContainer(vec1);
	cout << "Vector2:" << endl;
	vector<int> vec2;
	populateContainer(vec2);

	if (vec2.size() < vec1.size())
	{
		cout << "Vector2 should be at least the same size as vector1." << endl;
		return 1;
	}

	// Create a lambda to print a vector
	auto printVec = [](const vector<int>& vec){
		for (auto& i : vec) cout << i << " ";
		cout << endl;
	};

	cout << "Vector1: "; printVec(vec1);
	cout << "Vector2: "; printVec(vec2);

	transform(vec1.begin(), vec1.end(),
		vec2.begin(), vec1.begin(),
		[](int a, int b){return a+b;});

	cout << "Vector1: "; printVec(vec1);
	cout << "Vector2: "; printVec(vec2);

	return 0;
}
