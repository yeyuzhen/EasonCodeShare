#include <iostream>

using namespace std;

int main()
{
  int* ptr;
  int numInts = 10;

  ptr = new(nothrow) int[numInts];
  if (ptr == nullptr) {
    cerr << __FILE__ << "(" << __LINE__ << "): Unable to allocate memory!" << endl;
    // Handle memory allocation failure
    return 1;
  }
  // Proceed with function that assumes memory has been allocated

  return 0;
}
