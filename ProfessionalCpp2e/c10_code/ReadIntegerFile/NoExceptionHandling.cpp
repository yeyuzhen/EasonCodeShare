#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void readIntegerFile(const string& fileName, vector<int>& dest)
{
  ifstream istr;
  int temp;

  istr.open(fileName.c_str());

  // Read the integers one-by-one and add them to the vector
  while (istr >> temp) {
    dest.push_back(temp);
  }
}

int main()
{
  vector<int> myInts;
  const string fileName = "IntegerFile.txt";

  readIntegerFile(fileName, myInts);

  for (size_t i = 0; i < myInts.size(); i++) {
    cout << myInts[i] << " ";
  }
  cout << endl;

  return 0;
}
