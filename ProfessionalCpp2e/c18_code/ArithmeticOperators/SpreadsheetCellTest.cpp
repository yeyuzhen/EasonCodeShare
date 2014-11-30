#include "SpreadsheetCell.h"

#include <iostream>
using namespace std;

int main()
{
  int i, j = 4;
  i = -j; // unary minus
  i = +i; // unary plus
  j = +(-i); // apply unary plus to the result of applying unary minus to i
  j = -(-i); // apply unary minus to the result of applying unary minus to i

  i = i + 1;
  i += 1;
  ++i;
  i++;

  SpreadsheetCell c1(4);
  SpreadsheetCell c2(4);
  SpreadsheetCell c3;

  c1++;
  ++c2;
  c3 = -c1;

  return 0;
}
