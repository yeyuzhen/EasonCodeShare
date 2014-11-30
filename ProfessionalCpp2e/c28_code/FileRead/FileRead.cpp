#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile("FileRead.cpp");

	if (inFile.fail()) {
		cerr << "Unable to open file for reading." << endl;
		return 1;
	}

	string nextToken;
	while (inFile >> nextToken) {
		cout << "Token: " << nextToken << endl;
	}

	inFile.close();

	return 0;
}
