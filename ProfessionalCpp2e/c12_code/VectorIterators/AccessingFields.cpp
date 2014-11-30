#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<string> stringVector(10, "hello");

	for (auto it = stringVector.begin();
		it != stringVector.end(); ++it) {
			it->append(" there");
	}
/*
	// Using C++11 Range Based for loop
	for (auto& str : stringVector) {
		str.append(" there");
	}
*/
	return 0;
}
