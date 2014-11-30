#include <cstdio>
#include <cstdarg>
#include <iostream>
using namespace std;

bool debug = false;

void debugOut(char* str, ...)
{
  va_list ap;
  if (debug) {
    va_start(ap, str);
    vfprintf(stderr, str, ap);
    va_end(ap);
  }
}

void printInts(int num, ...)
{
  int temp;
  va_list ap;
  va_start(ap, num);
  for (int i = 0; i < num; i++) {
    temp = va_arg(ap, int);
    cout << temp << " ";
  }
  va_end(ap);
  cout << endl;
}

int main()
{
  debug = true;
  debugOut("int %d\n", 5);
  debugOut("String %s and int %d\n", "hello", 5);
  debugOut("Many ints: %d, %d, %d, %d, %d\n", 1, 2, 3, 4, 5);

  printInts(5, 5, 4, 3, 2, 1);

  return 0;
}

