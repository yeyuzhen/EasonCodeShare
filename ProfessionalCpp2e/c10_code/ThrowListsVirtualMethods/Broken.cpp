#include <stdexcept>
#include <iostream>

using namespace std;

class Base
{
public:
  virtual void func() throw(runtime_error) { cout << "Base!\n"; }
};

class Derived : public Base
{
public:
  virtual void func() throw(exception) // ERROR!
    { cout << "Derived!\n"; }
};

int main()
{
  return 0;
}
