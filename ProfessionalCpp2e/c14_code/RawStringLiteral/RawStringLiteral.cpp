#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = R"~(Line 1
line "2" \t (and)
end)~";

/*
string str = R"(Line 1
line "2" \t (and)
end)";
*/

	cout << "'" << str << "'" << endl;

	return 0;
}
