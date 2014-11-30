#include "Grid.h"

template <typename T>
class GameBoard : public Grid<T>
{
 public:
  GameBoard(size_t inWidth = Grid<T>::kDefaultWidth,
	    size_t inHeight = Grid<T>::kDefaultHeight);
  void move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest);
};

template <typename T>
GameBoard<T>::GameBoard(size_t inWidth, size_t inHeight) :
  Grid<T>(inWidth, inHeight)
{
}

template <typename T>
void GameBoard<T>::move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest)
{
  this->mCells[xDest][yDest] = this->mCells[xSrc][ySrc];
  this->mCells[xSrc][ySrc] = T(); // default construct the src cell
}
