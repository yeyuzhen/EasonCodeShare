// GridRefNonType.h

template <typename T, const T& EMPTY>
class Grid
{
public:
	Grid(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	Grid(const Grid<T, EMPTY>& src);
	virtual ~Grid();
	Grid<T, EMPTY>& operator=(const Grid<T, EMPTY>& rhs);

	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

protected:
	void copyFrom(const Grid<T, EMPTY>& src);
	T** mCells;
	size_t mWidth, mHeight;
};

template <typename T, const T& EMPTY>
Grid<T, EMPTY>::Grid(size_t inWidth, size_t inHeight) :
mWidth(inWidth), mHeight(inHeight)
{
	mCells = new T* [mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new T[mHeight];
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = EMPTY;
		}
	}
}

template <typename T, const T& EMPTY>
Grid<T, EMPTY>::Grid(const Grid<T, EMPTY>& src)
{
	copyFrom(src);
}

template <typename T, const T& EMPTY>
Grid<T, EMPTY>::~Grid()
{
	// free the old memory
	for (size_t i = 0; i < mWidth; i++) {
		delete [] mCells[i];
	}
	delete [] mCells;
	mCells = nullptr;
}

template <typename T, const T& EMPTY>
void Grid<T, EMPTY>::copyFrom(const Grid<T, EMPTY>& src)
{
	mWidth = src.mWidth;
	mHeight = src.mHeight;

	mCells = new T* [mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new T[mHeight];
	}

	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

template <typename T, const T& EMPTY>
Grid<T, EMPTY>& Grid<T, EMPTY>::operator=(const Grid<T, EMPTY>& rhs)
{
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}
	// free the old memory
	for (size_t i = 0; i < mWidth; i++) {
		delete [] mCells[i];
	}
	delete [] mCells;
	mCells = nullptr;

	// copy the new memory
	copyFrom(rhs);

	return *this;
}

template <typename T, const T& EMPTY>
void Grid<T, EMPTY>::setElementAt(size_t x, size_t y, const T& inElem)
{
	mCells[x][y] = inElem;
}

template <typename T, const T& EMPTY>
T& Grid<T, EMPTY>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y];
}

template <typename T, const T& EMPTY>
const T& Grid<T, EMPTY>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y];
}
