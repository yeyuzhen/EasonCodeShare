// hellovariables.cpp
//
// NOTE: Some C++ environments may report a runtime error
// when the uninitialized variable is accessed.

#include <iostream>

using namespace std;

int main()
{
  int uninitializedInt;
  int initializedInt = 7;

  cout << uninitializedInt << " is a random value" << endl;
  cout << initializedInt << " was assigned an initial value" << endl;

  return 0;
}
