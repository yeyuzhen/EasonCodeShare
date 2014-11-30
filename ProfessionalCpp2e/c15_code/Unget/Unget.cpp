#include <iostream>
#include <string>

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize = 0;
	// Read letters until we find a non-letter
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.unget();
			if (cin.fail())
				cout << "unget() failed" << endl;
			break;
		}
		guestName += ch;
	}
	// Read partysize
	cin >> partySize;

	cout << "Thank you '" << guestName
		<< "', party of " << partySize << endl;
	if (partySize > 10) {
		cout << "An extra gratuity will apply." << endl;
	}
}

int main()
{
	getReservationData();

	return 0;
}
