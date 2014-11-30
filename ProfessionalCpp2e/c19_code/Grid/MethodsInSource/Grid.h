// Grid.h

template <typename T>
class Grid
{
public:
	Grid(size_t inWidth = kDefaultWidth, size_t inHeight = kDefaultHeight);
	Grid(const Grid<T>& src);
	virtual ~Grid();
	Grid<T>& operator=(const Grid<T>& rhs);

	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;
	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }
	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

protected:
	void copyFrom(const Grid<T>& src);
	T** mCells;
	size_t mWidth, mHeight;
};

#include "Grid.cpp"
