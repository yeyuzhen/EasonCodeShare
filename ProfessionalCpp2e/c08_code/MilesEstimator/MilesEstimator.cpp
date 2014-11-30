#include "MilesEstimator.h"

int MilesEstimator::getMilesLeft() 
{
  return getMilesPerGallon() * getGallonsLeft();
}

void MilesEstimator::setGallonsLeft(int inValue) 
{
  mGallonsLeft = inValue; 
}

int MilesEstimator::getGallonsLeft() 
{ 
  return mGallonsLeft; 
}

int MilesEstimator::getMilesPerGallon() 
{ 
  return 20; 
}
