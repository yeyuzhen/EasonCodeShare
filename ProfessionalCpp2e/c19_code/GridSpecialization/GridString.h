// #includes for working with the C-style strings.
#include <cstdlib>
#include <cstring>
using namespace std;

// When the template specialization is used, the original template must be visible
// too. #including it here ensures that it will always be visible when this
// specialization is visible.
#include "Grid.h"

template <>
class Grid<char*>
{
public:
	Grid(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	Grid(const Grid<char*>& src);
	virtual ~Grid();
	Grid<char*>& operator=(const Grid<char*>& rhs);

	void setElementAt(size_t x, size_t y, const char* inElem);
	char* getElementAt(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;
protected:
	void copyFrom(const Grid<char*>& src);

	char*** mCells;
	size_t mWidth, mHeight;
};

Grid<char*>::Grid(size_t inWidth, size_t inHeight) :
mWidth(inWidth), mHeight(inHeight)
{
	mCells = new char** [mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new char* [mHeight];
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = nullptr;
		}
	}
}

Grid<char*>::Grid(const Grid<char*>& src)
{
	copyFrom(src);
}

Grid<char*>::~Grid()
{
	// free the old memory
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			delete [] mCells[i][j];
		}
		delete [] mCells[i];
	}
	delete [] mCells;
	mCells = nullptr;
}

void Grid<char*>::copyFrom(const Grid<char*>& src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;

	mCells = new char** [mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new char* [mHeight];
	}

	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			if (src.mCells[i][j] == nullptr) {
				mCells[i][j] = nullptr;
			} else {
				size_t len = strlen(src.mCells[i][j]) + 1;
				mCells[i][j] = new char[len];
				strncpy(mCells[i][j], src.mCells[i][j], len);
			}
		}
	}
}

Grid<char*>& Grid<char*>::operator=(const Grid<char*>& rhs)
{
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}
	// free the old memory
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			delete [] mCells[i][j];
		}
		delete [] mCells[i];
	}
	delete [] mCells;
	mCells = nullptr;

	// copy the new memory
	copyFrom(rhs);

	return *this;
}

void Grid<char*>::setElementAt(size_t x, size_t y, const char* inElem)
{
	delete [] mCells[x][y];
	if (inElem == nullptr) {
		mCells[x][y] = nullptr;
	} else {
		size_t len = strlen(inElem) + 1;
		mCells[x][y] = new char[len];
		strncpy(mCells[x][y], inElem, len);
	}
}

char* Grid<char*>::getElementAt(size_t x, size_t y) const
{
	if (mCells[x][y] == nullptr) {
		return nullptr;
	}
	size_t len = strlen(mCells[x][y]) + 1;
	char* ret = new char[len];
	strncpy(ret, mCells[x][y], len);

	return ret;
}
