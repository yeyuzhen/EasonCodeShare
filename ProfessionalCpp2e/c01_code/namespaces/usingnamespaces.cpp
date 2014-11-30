// usingnamespaces.cpp

#include "namespaces.h"

using namespace mycode;

int main()
{
  foo();  // implies mycode::foo();
  return 0;
}
