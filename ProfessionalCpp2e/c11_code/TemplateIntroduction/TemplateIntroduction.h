#include <stdexcept>

template<typename T>
class MyArray
{
public:
    MyArray(size_t size) : mSize(size), mArray(nullptr)
    {
        mArray = new T[size];
    }

    virtual ~MyArray()
    {
        if (mArray) {
            delete[] mArray;
            mArray = nullptr;
        }
    }
    
    size_t getSize() const { return mSize; }
    
    T& at(size_t index) throw(std::out_of_range)
    {
        if (index >= 0 && index < getSize())
            return mArray[index];
        else
            throw std::out_of_range("MyArray::at: Index out of range.");
    }

protected:
    size_t mSize;
    T* mArray;
};
