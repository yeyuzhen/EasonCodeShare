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

  // If your compiler does not support the C++11 auto
  // keyword, you need the following declaration for ret
  //pair<map<int, Data>::iterator, bool> ret;
  auto ret = dataMap.insert({1, Data(4)});  // Using C++11 initializer_list
  if (ret.second) {
    cout << "Insert succeeded!" << endl;
  } else {
    cout << "Insert failed!" << endl;
  }
  
  ret = dataMap.insert(make_pair(1, Data(6)));
  if (ret.second) {
    cout << "Insert succeeded!" << endl;
  } else {
    cout << "Insert failed!" << endl;
  }
  return 0;
}
