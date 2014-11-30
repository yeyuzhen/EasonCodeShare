#include <iostream>

using namespace std;

class Something
{
public:
  Something() { cout << "2"; }
  virtual ~Something() { cout << "2"; }
};

class Parent
{
public:
  Parent() { cout << "1"; }
  virtual ~Parent() { cout << "1"; }
};

class Child : public Parent
{
public:
  Child() { cout << "3"; }
  virtual ~Child() { cout << "3"; }

protected:
  Something mDataMember;
};

int main()
{
  Child myChild;
  return 0;
}
