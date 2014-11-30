#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

void funcOne() throw(exception);
void funcTwo() throw(exception);

int main()
{
  try {
    funcOne();
  } catch (const exception& e) {
    cerr << "Exception caught!" << endl;
    return 1;
  }

  return 0;
}

void funcOne() throw(exception)
{
  string str1;
  string* str2 = new string();
  funcTwo();
  delete str2;
}

void funcTwo() throw(exception)
{
  ifstream istr;
  istr.open("filename");
  throw exception();
  istr.close();
}
