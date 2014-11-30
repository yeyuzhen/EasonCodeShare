#include <map>
#include <iostream>
using namespace std;

class Data
{
public:
  Data(int val = 0) { mVal = val; }
  int getVal() const { return mVal; }
  void setVal(int val) { mVal = val; }
protected:
  int mVal;
};

int main()
{
  map<int, Data> dataMap;

  dataMap[1] = Data(4);
  dataMap[1] = Data(6); // replaces the element with key 1

  // Using C++11 auto keyword
  for (auto iter = dataMap.cbegin(); iter != dataMap.cend(); ++iter) {
    cout << iter->second.getVal() << endl;
  }

  // Using C++11 range-based for loop
  for (auto& p : dataMap) {
    cout << p.second.getVal() << endl;
  }

  // If your compiler does not support the above C++11 version:
  for (map<int, Data>::const_iterator iter = dataMap.begin();
       iter != dataMap.end(); ++iter) {
    cout << iter->second.getVal() << endl;
  }

  return 0;
}
