// TestCherry.cpp

#include <iostream>

#include "BingCherry.h"
#include "BingCherryTree.h"

int main()
{
  BingCherryTree theTree;
  Cherry* theCherry = theTree.pick();
  theCherry->printType();
  delete theCherry;
  return 0;
}

