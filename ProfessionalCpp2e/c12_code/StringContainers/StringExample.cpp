#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str1;

	str1.insert(str1.end(), 'h');
	str1.insert(str1.end(), 'e');
	str1.insert(str1.end(), 'l');
	str1.insert(str1.end(), 'l');
	str1.insert(str1.end(), 'o');

	for (auto it = str1.cbegin(); it != str1.cend(); ++it) {
		cout << *it;
	}
	cout << endl;

	for (auto& letter : str1) {
		cout << letter;
	}
	cout << endl;

	return 0;
}
