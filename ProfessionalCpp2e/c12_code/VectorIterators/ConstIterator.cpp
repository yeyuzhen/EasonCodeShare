#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	vector<string> stringVector(10, "hello");
	for (auto iter = stringVector.cbegin();
		iter != stringVector.cend(); ++iter) {
			cout << *iter << endl;
	}

	return 0;
}
