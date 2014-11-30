// Matrix.h
#include <stdexcept>
#include "Element.h"

class Matrix
{
public:
	Matrix(unsigned int width, unsigned int height) throw(std::bad_alloc);
	virtual ~Matrix();

protected:
	unsigned int mWidth;
	unsigned int mHeight;
	Element** mMatrix;
};