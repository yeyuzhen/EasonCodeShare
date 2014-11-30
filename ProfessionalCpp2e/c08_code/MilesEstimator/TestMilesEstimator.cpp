#include "EfficientCarMilesEstimator.h"
#include <iostream>

using namespace std;

int main()
{
  MilesEstimator myMilesEstimator;
  
  myMilesEstimator.setGallonsLeft(2);
  cout << "Normal estimator can go " << myMilesEstimator.getMilesLeft() << " more miles." << endl;
  
  EfficientCarMilesEstimator myEstimator;
  
  myEstimator.setGallonsLeft(2);
  cout << "Efficient estimator can go " << myEstimator.getMilesLeft() << " more miles." << endl;

  return 0;
}
