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
	while (true) {
		// 'peek' at next character
		ch = cin.peek();
		if (!cin.good())
			break;
		if (isdigit(ch)) {
			// next character will be a digit, so stop the loop
			break;
		}
		// next character will be a non-digit, so read it
		cin >> ch;
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
