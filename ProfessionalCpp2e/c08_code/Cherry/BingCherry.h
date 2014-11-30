// BingCherry.h

#include <iostream>
#include "Cherry.h"

using namespace std;

class BingCherry : public Cherry {

 public:
  BingCherry() {};

  virtual void printType() { cout << "I am a Bing Cherry" << endl; };

  virtual void polish() {  }
};
