#include <stdexcept>
#include <iostream>

using namespace std;

class Base
{
public:
  virtual void func() throw(exception) { cout << "Base!\n"; }
};

class Derived : public Base
{
public:
  virtual void func() noexcept { cout << "Derived!\n"; }
};

int main()
{
  return 0;
}
