// typetest.cpp

#include <iostream>

using namespace std;

int main()
{
  int someInteger = 256;
  short someShort;
  long someLong;
  float someFloat;
  double someDouble;

  someInteger++;
  someInteger *= 2;
  someShort = (short)someInteger;
  someLong = someShort * 10000;
  someFloat = someLong + 0.785;
  someDouble = (double)someFloat / 100000;

  cout << someDouble << endl;

  return 0;
}
