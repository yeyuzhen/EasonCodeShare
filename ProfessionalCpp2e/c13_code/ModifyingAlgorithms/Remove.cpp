#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void removeEmptyStrings(vector<string>& strings)
{
	auto it = remove_if(strings.begin(), strings.end(),
		[](const string& str){return str.empty();}); 
	// erase the removed elements
	strings.erase(it, strings.end());
}

int main()
{
	vector<string> myVector = {"", "one", "", "two", "three", "four"};

	for (auto& str : myVector) cout << "\"" << str << "\"  ";
	cout << endl;
	removeEmptyStrings(myVector);
	for (auto& str : myVector) cout << "\"" << str << "\"  ";
	cout << endl;

	return 0;
}
