#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

void readIntegerFile(const string& fileName, vector<int>& dest)
  throw (invalid_argument, runtime_error)
{
  ifstream istr;
  int temp;

  istr.open(fileName.c_str());
  if (istr.fail()) {
    // We failed to open the file: throw an exception
    string error = "Unable to open file " + fileName;
    throw invalid_argument(error);
  }

  // Read the integers one-by-one and add them to the vector
  while (istr >> temp) {
    dest.push_back(temp);
  }

  if (istr.eof()) {
    // We reached the end-of-file.
    istr.close();
  } else {
    // Some other error. Throw an exception
    istr.close();
    string error = "Unable to read file " + fileName;
    throw runtime_error(error);
  }
}

int main()
{
  vector<int> myInts;
  const string fileName = "IntegerFile.txt";

  try {
    readIntegerFile(fileName, myInts);
  } catch (const invalid_argument& e) {
    cerr << e.what() << endl;
    return 1;
  } catch (const runtime_error& e) {
    cerr << e.what() << endl;
    return 1;
  }

  for (size_t i = 0; i < myInts.size(); i++) {
    cout << myInts[i] << " ";
  }
  cout << endl;

  return 0;
}
