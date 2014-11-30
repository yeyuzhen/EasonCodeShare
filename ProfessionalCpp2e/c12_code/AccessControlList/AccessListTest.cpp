#include "AccessList.h"
#include <iostream>

using namespace std;

int main()
{
	AccessList fileX = {"nsolter", "klep", "baduser"};
	fileX.removeUser("baduser");

	if (fileX.isAllowed("nsolter")) {
		cout << "nsolter has permissions" << endl;
	}

	if (fileX.isAllowed("baduser")) {
		cout << "baduser has permissions" << endl;
	}

	auto users = fileX.getAllUsers();
	for (auto& user : users) {
		cout << user << "  ";
	}
	cout << endl;

	return 0;
}
