int main()
{
  int x = 3, y = 4, z = 5;
  int& xRef = x;
  xRef = 10;
  //  int& emptyRef; // DOES NOT COMPILE!

  //  int& unnamedRef1 = 5; // DOES NOT COMPILE
  const int& unnamedRef2 = 5; // works as expected

  xRef = y; // changes value of x to 4. Doesn't make xRef refer to y.

  int& zRef = z;
  zRef = xRef; // Assigns values, not references

  int* intP;
  int*& ptrRef = intP;
  ptrRef = new int;
  *ptrRef = 5;

  int* xPtr = &xRef; // address of a reference is pointer to value
  *xPtr = 100;

  //  int&& xDoubleRef = xRef; // DOES NOT COMPILE!
  // int&* refPtr = &xRef; // DOES NOT COMPILE!

  return 0;
}
