template <typename T, size_t WIDTH, size_t HEIGHT>
class Grid
{
public:
	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;
	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }

protected:
	T mCells[WIDTH][HEIGHT];
};

template <typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::setElementAt(size_t x, size_t y, const T& inElem)
{
	mCells[x][y] = inElem;
}

template <typename T, size_t WIDTH, size_t HEIGHT>
T& Grid<T, WIDTH, HEIGHT>::getElementAt(size_t x, size_t y)
{
	return mCells[x][y];
}

template <typename T, size_t WIDTH, size_t HEIGHT>
const T& Grid<T, WIDTH, HEIGHT>::getElementAt(size_t x, size_t y) const
{
	return mCells[x][y];
}
