#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Returns false on error
bool changeNumberForID(const string& inFileName, int inID,
	const string& inNewNumber);

int main()
{
	changeNumberForID("data.txt", 263, "415-555-3333");

	return 0;
}

bool changeNumberForID(const string& inFileName, int inID,
	const string& inNewNumber)
{
	fstream ioData(inFileName.c_str());
	if (!ioData) {
		cerr << "Error while opening file " << inFileName << endl;
		return false;
	}

	// Loop until the end of file
	while (ioData.good()) {
		int id;
		string number;

		// Read the next ID.
		ioData >> id;

		// Check to see if the current record is the one being changed.
		if (id == inID) {
			// Seek to the current read position
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number.
			ioData << " " << inNewNumber;
			break;
		}

		// Read the current number to advance the stream.
		ioData >> number;
	}
	return true;
}
