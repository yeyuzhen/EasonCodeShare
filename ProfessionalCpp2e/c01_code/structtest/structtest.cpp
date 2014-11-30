// structtest.cpp

#include <iostream>
#include "employeestruct.h"

using namespace std;

int main ()
{
  // create and populate an employee
  EmployeeT anEmployee;

  anEmployee.firstInitial = 'M';
  anEmployee.middleInitial = 'R';
  anEmployee.lastInitial = 'G';
  anEmployee.employeeNumber = 42;
  anEmployee.salary = 80000;

  // output the values of an employee
  cout << "Employee: " << anEmployee.firstInitial << 
                          anEmployee.middleInitial <<
                          anEmployee.lastInitial << endl;
  cout << "Number: " << anEmployee.employeeNumber << endl;
  cout << "Salary: $" << anEmployee.salary << endl;

  return 0;
}
