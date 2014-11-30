#include <iostream>
#include <string>

using namespace std;

string readName(istream& inStream);

int main()
{
	cout << "Reading a name from cin. You can usually close cin with Control-D (Control-Z in Windows): ";
	string theName = readName(cin);

	cout << "The name is " << theName << endl;

	return 0;
}
/*
string readName(istream& inStream)
{
	string name;
	while (inStream.good()) {
		int next = inStream.get();
		if (next == EOF)
			break;
		name += next;// Implicitly convert to a char and append. 
	}
	return name;
}
*/
string readName(istream& inStream)
{
	string name;
	char next;
	while (inStream.get(next)) {
		name += next;
	}

	return name;
}
