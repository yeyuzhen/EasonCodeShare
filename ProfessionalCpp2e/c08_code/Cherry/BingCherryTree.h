// BingCherryTree.h

#include <iostream>

#include "CherryTree.h"

using namespace std;

class BingCherryTree : public CherryTree {

 public:
  BingCherryTree() {};

  virtual BingCherry* pick() { 
    BingCherry* theCherry = new BingCherry(); 
    
    theCherry->polish();
  
    return theCherry;
  }

};
