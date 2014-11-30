#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

using namespace std;

class FileError : public runtime_error
{
public:
  FileError(const string& fileIn) : runtime_error(""), mFile(fileIn) {}
  virtual const char* what() const noexcept { return mMsg.c_str(); }
  string getFileName() { return mFile; }

protected:
  string mFile, mMsg;
};

class FileOpenError : public FileError
{
public:
  FileOpenError(const string& fileNameIn);
};

FileOpenError::FileOpenError(const string& fileNameIn) : FileError(fileNameIn)
{
  mMsg = "Unable to open " + fileNameIn;
}

class FileReadError : public FileError
{
public:
  FileReadError(const string& fileNameIn, int lineNumIn);
  int getLineNum() { return mLineNum; }

protected:
  int mLineNum;
};

FileReadError::FileReadError(const string& fileNameIn, int lineNumIn) :
  FileError(fileNameIn), mLineNum(lineNumIn)
{
  ostringstream ostr;

  ostr << "Error reading " << fileNameIn << " at line " << lineNumIn;
  mMsg = ostr.str();
}

void readIntegerFile(const string& fileName, vector<int>& dest)
  throw (FileOpenError, FileReadError) 
{
  ifstream istr;
  int temp;
  string line;
  int lineNumber = 0;

  istr.open(fileName.c_str());
  if (istr.fail()) {
    // We failed to open the file: throw an exception
    throw FileOpenError(fileName);
  }

  while (!istr.eof()) {
    // Read one line from the file
    getline(istr, line);
    lineNumber++;

    // Create a string stream out of the line
    istringstream lineStream(line);

    // Read the integers one-by-one and add them to the vector
    while (lineStream >> temp) {
      dest.push_back(temp);
    }

    if (!lineStream.eof()) {
      // Some other error. Close the file and throw an exception.
      istr.close();
      throw FileReadError(fileName, lineNumber);
    }
  }
  istr.close();
}

int main()
{
  vector<int> myInts;
  const string fileName = "IntegerFile.txt";

  try {
    readIntegerFile(fileName, myInts);
  } catch (const FileError& e) {
    cerr << e.what() << endl;
    return 1;
  }

  for (unsigned int i = 0; i < myInts.size(); i++) {
    cout << myInts[i] << " ";
  }
  cout << endl;

  return 0;
}
