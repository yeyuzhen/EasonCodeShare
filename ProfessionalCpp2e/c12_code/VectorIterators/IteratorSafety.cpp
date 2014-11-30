#include <vector>
using namespace std;

int main()
{
  vector<int> intVector;

  auto it = intVector.end();
  *it = 10; // BUG! it doesn't refer to a valid element

  vector<int> vectorOne(10);
  vector<int> vectorTwo(10);

  // fill in the vectors

  // BUG! infinite loop
  for (auto it = vectorTwo.begin(); it != vectorOne.end(); ++it) {
    // loop body
  }

  return 0;
} 
