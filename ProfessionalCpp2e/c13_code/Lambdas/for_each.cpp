#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vec = {11,22,33,44};
	int index = 0;
	for_each(vec.begin(), vec.end(),
		[&index](int i){cout << "Value " << (index++) << ": " << i << endl;});

	return 0;
}