#include <iostream>

class MilesEstimator
{
public:
  virtual int getMilesLeft();

  virtual void setGallonsLeft(int inValue);
  virtual int  getGallonsLeft();
private:
  int mGallonsLeft;
  virtual int getMilesPerGallon();
};
