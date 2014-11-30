#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fout("test.out");
	if (!fout) {
		cerr << "Error opening test.out for writing" << endl;
		return 1;
	}

	// 1. output the string "12345"
	fout << "12345";

	// 2. verify that the marker is at position 5
	ios_base::streampos curPos = fout.tellp();
	if (5 == curPos) {
		cout << "Test passed: Currently at position 5" << endl;
	} else {
		cout << "Test failed: Not at position 5" << endl;
	}

	// 3. move to position 2 in the stream
	fout.seekp(2, ios_base::beg);

	// 4. output a 0 in position 2 and close the stream
	fout << 0;
	fout.close();

	// 5. open an input stream on test.out
	ifstream fin("test.out");
	if (!fin) {
		cerr << "Error opening test.out for reading" << endl;
		return 1;
	}

	// 6. read the first token as an integer
	int testVal;
	fin >> testVal;

	// 7. confirm that the value is 12045
	const int expected = 12045;
	if (testVal == expected) {
		cout << "Test passed: Value is " << expected << endl;
	} else {
		cout << "Test failed: Value is not " << expected
			 << " (it was " << testVal << ")" << endl;
	}

	return 0;
}
