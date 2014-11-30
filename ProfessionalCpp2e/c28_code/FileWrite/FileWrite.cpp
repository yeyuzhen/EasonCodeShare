#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream outFile("FileWrite.out");
	if (outFile.fail()) {
		cerr << "Unable to open file for writing." << endl;
		return 1;
	}
	outFile << "Hello!" << endl;
	outFile.close();

	ofstream appendFile("FileWrite.out", ios_base::app);
	if (appendFile.fail()) {
		cerr << "Unable to open file for appending." << endl;
		return 2;
	}
	appendFile << "Append!" << endl;
	appendFile.close();

	return 0;
}
