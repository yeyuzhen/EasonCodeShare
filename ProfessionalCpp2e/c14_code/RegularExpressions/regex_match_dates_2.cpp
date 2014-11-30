// regex_match_dates_2.cpp
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	regex r("^(\\d{4})/(0?[1-9]|1[0-2])/(0?[1-9]|[1-2][0-9]|3[0-1])$");
	while (true)  {
		cout << "Enter a date (year/month/day) (q=quit): ";
		string str;
		if (!getline(cin, str) || str == "q")
			break;

		smatch m;
		if (regex_match(str, m, r)) {
			int year = atoi(m[1].str().c_str());
			int month = atoi(m[2].str().c_str());
			int day = atoi(m[3].str().c_str());
			cout << "  Valid date: Year=" << year << ", month=" << month << ", day=" << day << endl;
		} else {
			cout << "  Invalid date!" << endl;
		}
	}

	return 0;
}