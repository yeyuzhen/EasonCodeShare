#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

void printVector(const vector<int>& v)
{
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}

int main()
{
  vector<int> vectorOne = {1,2,3,5};
  vector<int> vectorTwo;

  // oops, we forgot to add 4. Insert it in the correct place
  vectorOne.insert(vectorOne.begin() + 3, 4);

  // Add elements 6 through 10 to vectorTwo
  for (int i = 6; i <= 10; i++) {
    vectorTwo.push_back(i);
  }

  printVector(vectorOne);
  printVector(vectorTwo);

  // add all the elements from vectorTwo to the end of vectorOne
  vectorOne.insert(vectorOne.end(), vectorTwo.begin(), vectorTwo.end());
  printVector(vectorOne);

  // now erase the numbers 2 through 5 in vectorOne
  vectorOne.erase(vectorOne.begin() + 1, vectorOne.begin() + 5);
  printVector(vectorOne);

  // clear vectorTwo entirely
  vectorTwo.clear();

  // And add 10 copies of the value 100
  vectorTwo.insert(vectorTwo.begin(), 10, 100);

  // Decide we only want 9 elements
  vectorTwo.pop_back();

  printVector(vectorTwo);

  return 0;
}
