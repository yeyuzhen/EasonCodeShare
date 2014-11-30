// regex_token_iterator_field_splitting.cpp
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	regex reg("\\s*[,;]+\\s*");
	while (true) {
		cout << "Enter a string to split on ',' and ';' (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q")
			break;
		
		const sregex_token_iterator end;
		for (sregex_token_iterator iter(str.begin(), str.end(), reg, -1);
			iter != end; ++iter) {
			cout << "\"" << *iter << "\"" << endl;
		}
	}

	return 0;
}