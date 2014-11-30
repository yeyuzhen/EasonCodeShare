// CherryTree.h

#include <iostream>

using namespace std;

class CherryTree {

 public:
  CherryTree() {};

  virtual Cherry* pick() { return new Cherry(); }

};
