// UserInterface.cpp

#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);

int main()
{
  Database employeeDB;
  bool done = false;

  while (!done) {
    int selection = displayMenu();

    switch (selection) {
    case 1:
      doHire(employeeDB);
      break;
    case 2:
      doFire(employeeDB);
      break;
    case 3:
      doPromote(employeeDB);
      break;
    case 4:
      employeeDB.displayAll();
      break;
    case 5:
      employeeDB.displayCurrent();
      break;
    case 6:
      employeeDB.displayFormer();
      break;
    case 0:
      done = true;
      break;
    default:
      cerr << "Unknown command." << endl;
    }
  }
  return 0;
}

int displayMenu()
{
  int selection;

  cout << endl;
  cout << "Employee Database" << endl;
  cout << "-----------------" << endl;
  cout << "1) Hire a new employee" << endl;
  cout << "2) Fire an employee" << endl;
  cout << "3) Promote an employee" << endl;
  cout << "4) List all employees" << endl;
  cout << "5) List all current employees" << endl;
  cout << "6) List all previous employees" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "---> ";

  cin >> selection;

  return selection;
}

void doHire(Database& inDB)
{
  string firstName;
  string lastName;

  cout << "First name? ";
  cin >> firstName;
  cout << "Last name? ";
  cin >> lastName;

  try {
    inDB.addEmployee(firstName, lastName);
  } catch (const std::exception&) { 
    cerr << "Unable to add new employee!" << endl;
  }
}

void doFire(Database& inDB)
{
  int employeeNumber;

  cout << "Employee number? ";
  cin >> employeeNumber;

  try {
    Employee& emp = inDB.getEmployee(employeeNumber);
    emp.fire();
    cout << "Employee " << employeeNumber << " has been terminated." << endl;
  } catch (const std::exception&) {
    cerr << "Unable to terminate employee!" << endl;
  }
}

void doPromote(Database& inDB)
{
  int employeeNumber;
  int raiseAmount;

  cout << "Employee number? ";
  cin >> employeeNumber;

  cout << "How much of a raise? ";
  cin >> raiseAmount;

  try {
    Employee& emp = inDB.getEmployee(employeeNumber);
    emp.promote(raiseAmount);
  } catch (const std::exception&) {
    cerr << "Unable to promote employee!" << endl;
  }
}
