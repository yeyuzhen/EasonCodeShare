template <typename T>
class OneDGrid
{
public:
	OneDGrid(size_t inSize = kDefaultSize);
	OneDGrid(const OneDGrid<T>& src);
	virtual ~OneDGrid();

	OneDGrid<T>& operator=(const OneDGrid<T>& rhs);
	void resize(size_t newSize);

	T& operator[](size_t x);
	const T& operator[](size_t x) const;
	size_t getSize() const { return mSize; }
	static const size_t kDefaultSize = 10;
protected:
	void copyFrom(const OneDGrid<T>& src);
	T* mElems;
	size_t mSize;
};

template <typename T>
OneDGrid<T>::OneDGrid(size_t inSize) : mSize(inSize)
{
	mElems = new T[mSize];
}

template <typename T>
OneDGrid<T>::OneDGrid(const OneDGrid<T>& src)
{
	copyFrom(src);
}

template <typename T>
OneDGrid<T>::~OneDGrid()
{
	delete [] mElems;
	mElems = nullptr;
}

template <typename T>
void OneDGrid<T>::copyFrom(const OneDGrid<T>& src)
{
	mSize = src.mSize;
	mElems = new T[mSize];

	for (size_t i = 0; i < mSize; i++) {
		mElems[i] = src.mElems[i];
	}
}

template <typename T>
OneDGrid<T>& OneDGrid<T>::operator=(const OneDGrid<T>& rhs)
{
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}

	// free the old memory
	delete [] mElems;
	mElems = nullptr;

	// copy the new memory
	copyFrom(rhs);
	return *this;
}

template <typename T>
void OneDGrid<T>::resize(size_t newSize)
{
	T* newElems = new T[newSize]; // Allocate the new array of the new size

	// Handle the new size being smaller or bigger than the old size
	for (size_t i = 0; i < newSize && i < mSize; i++) {
		// Copy the elements from the old array to the new one
		newElems[i] = mElems[i];
	}
	mSize = newSize;   // store the new size
	delete [] mElems;  // free the memory for the old array
	mElems = newElems; // Store the pointer to the new array
}

template <typename T>
T& OneDGrid<T>::operator[](size_t x)
{
	return mElems[x];
}

template <typename T>
const T& OneDGrid<T>::operator[](size_t x) const
{
	return mElems[x];
}

