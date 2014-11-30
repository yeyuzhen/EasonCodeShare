#include "Grid.h"
#include <cstdlib>
#include <cstring>

template <size_t WIDTH, size_t HEIGHT>
class Grid<char*, WIDTH, HEIGHT>
{
public:
	Grid();
	Grid(const Grid<char*, WIDTH, HEIGHT>& src);
	virtual ~Grid();

	Grid<char*, WIDTH, HEIGHT>& operator=(const Grid<char*, WIDTH, HEIGHT>& rhs);
	void setElementAt(size_t x, size_t y, const char* inElem);
	char* getElementAt(size_t x, size_t y) const;
	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }
protected:
	void copyFrom(const Grid<char*, WIDTH, HEIGHT>& src);
	char* mCells[WIDTH][HEIGHT];
};

template <size_t WIDTH, size_t HEIGHT>
Grid<char*, WIDTH, HEIGHT>::Grid()
{
	for (size_t i = 0; i < WIDTH; i++) {
		for (size_t j = 0; j < HEIGHT; j++) {
			// initialize each element to nullptr
			mCells[i][j] = nullptr;
		}
	}
}

template <size_t WIDTH, size_t HEIGHT>
Grid<char*, WIDTH, HEIGHT>::Grid(const Grid<char*, WIDTH, HEIGHT>& src)
{
	copyFrom(src);
}

template <size_t WIDTH, size_t HEIGHT>
Grid<char*, WIDTH, HEIGHT>::~Grid()
{
	for (size_t i = 0; i < WIDTH; i++) {
		for (size_t j = 0; j < HEIGHT; j++) {
			delete [] mCells[i][j];
		}
	}
}

template <size_t WIDTH, size_t HEIGHT>
void Grid<char*, WIDTH, HEIGHT>::copyFrom(
	const Grid<char*, WIDTH, HEIGHT>& src)
{
	for (size_t i = 0; i < WIDTH; i++) {
		for (size_t j = 0; j < HEIGHT; j++) {
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

template <size_t WIDTH, size_t HEIGHT>
Grid<char*, WIDTH, HEIGHT>& Grid<char*, WIDTH, HEIGHT>::operator=(
	const Grid<char*, WIDTH, HEIGHT>& rhs)
{
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}
	// free the old memory
	for (size_t i = 0; i < WIDTH; i++) {
		for (size_t j = 0; j < HEIGHT; j++) {
			delete [] mCells[i][j];
			mCells[i][j] = nullptr;
		}
	}

	// copy the new memory
	copyFrom(rhs);
	return *this;
}

template <size_t WIDTH, size_t HEIGHT>
void Grid<char*, WIDTH, HEIGHT>::setElementAt(
	size_t x, size_t y, const char* inElem)
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

template <size_t WIDTH, size_t HEIGHT>
char* Grid<char*, WIDTH, HEIGHT>::getElementAt(size_t x, size_t y) const
{
	if (mCells[x][y] == nullptr) {
		return nullptr;
	}
	size_t len = strlen(mCells[x][y]) + 1;
	char* ret = new char[len];
	strncpy(ret, mCells[x][y], len);

	return ret;
}

