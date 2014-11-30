#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	cout << "Enter tokens. Control+D (Unix) or Control+Z (Windows) to end." << endl;

	ostringstream outStream;

	while (cin) {
		string nextToken;

		cout << "Next token: ";
		cin >> nextToken;

		if (nextToken == "done")
			break;

		outStream << nextToken << "\t";        
	}

	cout << "The end result is: " << outStream.str();

	return 0;
}
