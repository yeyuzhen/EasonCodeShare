class Array
{
public:
	// Creates an array with a default size that will grow as needed.
	Array();
	virtual ~Array();
	
	int& operator[](size_t x);
	const int& operator[](size_t x) const;
	//const int& operator[](size_t x);  // BUG! Can't overload based on return type

	//// Returns the value at index x. If index x does not exist in the array,
	//// throws an exception of type out_of_range.
	//int getElementAt(size_t x) const;
	//// Sets the value at index x to val. If index x is out of range,
	//// allocates more space to make it in range.
	//void setElementAt(size_t x, int val);

protected:
	static const size_t kAllocSize = 4;
	void resize(size_t newSize);
	// Sets all elements to 0
	void initializeElements();
	int* mElems;
	size_t mSize;
private:
	// Disallow assignment and pass-by-value
	Array(const Array& src);
	Array& operator=(const Array& rhs);
};
