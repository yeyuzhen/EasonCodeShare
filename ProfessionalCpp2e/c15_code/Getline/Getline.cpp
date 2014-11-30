#include <iostream>
#include <string>

using namespace std;

const int kBufferSize = 1024;

int main()
{
	char buffer[kBufferSize];
	cin.getline(buffer, kBufferSize);

	cout << "***" << buffer << "***" << endl;

	string myString;
	std::getline(cin, myString);

	cout << "***" << myString << "***" << endl;

	return 0;
}
