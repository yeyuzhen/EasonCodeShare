// stringtest2.cpp

#include <string>
#include <iostream>

using namespace std;

int main()
{
  string str1 = "Hello";
  string str2 = "World";
  string str3 = str1 + " " + str2;

  cout << "str1 is " << str1 << endl;
  cout << "str2 is " << str2 << endl;
  cout << "str3 is " << str3 << endl;

  if (str3 == "Hello World") {
    cout << "str3 is what it should be" << endl;
  } else {
    cout << "hmmm... str3 isn't what it should be" << endl;
  }

  return 0;
}
