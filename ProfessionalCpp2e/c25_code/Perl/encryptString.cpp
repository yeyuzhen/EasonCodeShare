#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string encrypt(const char* input);

int main(int argc, char* argv[])
{
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " string-to-be-encrypted" << endl;
		return -1;
	}

	cout << encrypt(argv[1]);

	return 0;
} 

/**
* Performs a very weak form of "encryption" by 
* adding 13 to each character of the string.
*/
string encrypt(const char* input)
{
	char* encrypted = new char[strlen(input) + 1];

	for (unsigned int i = 0; i < strlen(input); i++) {
		encrypted[i] = input[i] + 13;
	}
	encrypted[strlen(input)] = '\0';

	string result(encrypted);

	delete [] encrypted;

	return result;
}
