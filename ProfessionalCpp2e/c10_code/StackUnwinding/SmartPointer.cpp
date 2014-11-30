#include <fstream>
#include <iostream>
#include <stdexcept>
#include <memory>

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
  unique_ptr<string> str2(new string("hello"));
  funcTwo();
}

void funcTwo() throw(exception)
{
  ifstream istr;
  istr.open("filename");
  throw exception();
  istr.close();
}
