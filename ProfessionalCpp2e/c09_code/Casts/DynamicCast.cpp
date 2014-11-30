#include <typeinfo>
#include <iostream>
using namespace std;

class Base
{
public:
  Base() {};
  virtual ~Base() {}
};

class Derived : public Base
{
public:
  Derived() {}
  virtual ~Derived() {}
};

int main()
{
  Base* b;
  Derived* d = new Derived();

  b = d;
  d = dynamic_cast<Derived*>(b);

  Base base;
  Derived derived;

  Base& br = base;

  try {
    Derived& dr = dynamic_cast<Derived&>(br);
  } catch (const bad_cast&) {
    cout << "Bad cast!\n";
  }

  return 0;
}
