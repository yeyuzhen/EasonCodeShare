template <typename T, size_t WIDTH = 10, size_t HEIGHT = 10>
class Grid
{
public:
	// Writing a copy constructor (even a templatized one)
	// prevents the compiler from generating a default constructor
	Grid() {}

	template <typename E, size_t WIDTH2, size_t HEIGHT2>
	Grid(const Grid<E, WIDTH2, HEIGHT2>& src);

	template <typename E, size_t WIDTH2, size_t HEIGHT2>
	Grid<T, WIDTH, HEIGHT>& operator=(const Grid<E, WIDTH2, HEIGHT2>& rhs);

	void setElementAt(size_t x, size_t y, const T& inElem);
	T& getElementAt(size_t x, size_t y);
	const T& getElementAt(size_t x, size_t y) const;
	size_t getHeight() const { return HEIGHT; }
	size_t getWidth() const { return WIDTH; }

protected:
	template <typename E, size_t WIDTH2, size_t HEIGHT2>
	void copyFrom(const Grid<E, WIDTH2, HEIGHT2>& src);

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

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2>& src)
{
	copyFrom(src);
}

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>& Grid<T, WIDTH, HEIGHT>::operator=(
	const Grid<E, WIDTH2, HEIGHT2>& rhs)
{
	// no need to check for self-assignment because this version of
	// assignment is never called when T and E are the same

	// No need to free any memory first
	copyFrom(rhs);
	return *this;
}

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
void Grid<T, WIDTH, HEIGHT>::copyFrom(
	const Grid<E, WIDTH2, HEIGHT2>& src)
{
	for (size_t i = 0; i < WIDTH; i++) {
		for (size_t j = 0; j < HEIGHT; j++) {
			if (i < WIDTH2 && j < HEIGHT2) {
				mCells[i][j] = src.getElementAt(i, j);
			} else {
				mCells[i][j] = T();
			}
		}

	}
}
