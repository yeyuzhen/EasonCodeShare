#include "hashmap.h"
#include <iostream>
#include <map>
using namespace std;

int main()
{
	/*hashmap<string, int> myHash;
	myHash.insert(make_pair(“KeyOne”, 100));
	myHash.insert(make_pair(“KeyTwo”, 200));
	myHash.insert(make_pair(“KeyThree”, 300));*/

	hashmap<string, int> myHash = {
		{"KeyOne", 100},
		{"KeyTwo", 200}};

	myHash.insert({
		{"KeyThree", 300},
		{"KeyFour", 400}});

	for (auto it = myHash.cbegin(); it != myHash.cend(); ++it) {
		// Use both -> and * to test the operations
		cout << it->first << " maps to " << (*it).second << endl;
	}

	cout << "----" << endl;

	// Print elements using C++11 range-based for loop
	for (auto& p : myHash)
		cout << p.first << " maps to " << p.second << endl;

	cout << "----" << endl;

	// Create a map with all the elements in the hashmap
	map<string, int> myMap(myHash.begin(), myHash.end());
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		cout << it->first << " maps to " << (*it).second << endl;
	}

	hashmap<string, int> myHash2;
	myHash.swap(myHash2);
	hashmap<string, int>myHash3(myHash2);

	cout << myHash2.size() << endl;
	cout << myHash2.max_size() << endl;

	return 0;
}
