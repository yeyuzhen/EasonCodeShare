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

  b = d; // Don't need a cast to go up the inheritance hierarchy
  d = static_cast<Derived*>(b); // Need a cast to go down the hierarchy

  Base base;
  Derived derived;

  Base& br = derived;
  Derived& dr = static_cast<Derived&>(br);

  int i = 3;
  double result = static_cast<double>(i) / 10;

  return 0;
}
