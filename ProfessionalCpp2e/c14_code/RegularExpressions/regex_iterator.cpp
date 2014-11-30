// regex_iterator.cpp
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	regex reg("[\\w]+");
	while (true) {
		cout << "Enter a string to split (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q")
			break;
		
		const sregex_iterator end;
		for (sregex_iterator it(str.begin(), str.end(), reg); it != end; ++it) {
			cout << "\"" << (*it)[0] << "\"" << endl;
		}
	}

	return 0;
}