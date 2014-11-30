#include "hashmap.h"
#include <iostream>
using namespace std;

int main()
{
	hashmap<int, int> myHash;
	myHash.insert(make_pair(4, 40));
	myHash.insert(make_pair(6, 60));

	// x will have type hashmap<int, int>::value_type*
	auto x = myHash.find(4);
	if (x != nullptr) {
		cout << "4 maps to " << x->second << endl;
	} else {
		cout << "cannot find 4 in map" << endl;
	}

	myHash.erase(4);

	auto x2 = myHash.find(4);
	if (x2 != nullptr) { 
		cout << "4 maps to " << x2->second << endl;
	} else {
		cout << "cannot find 4 in map" << endl;
	}

	myHash[4] = 35;
	myHash[4] = 60;

	auto x3 = myHash.find(4);
	if (x3 != nullptr) { 
		cout << "4 maps to " << x3->second << endl;
	} else {
		cout << "cannot find 4 in map" << endl;
	}

	return 0;
}
