#include <map>
#include <iostream>
#include <stdexcept>

template <typename T>
class SuperSmartPointer
{
public:
	explicit SuperSmartPointer(T* inPtr);
	virtual ~SuperSmartPointer();

	SuperSmartPointer(const SuperSmartPointer<T>& src);
	SuperSmartPointer<T>& operator=(const SuperSmartPointer<T>& rhs);

	const T& operator*() const;
	const T* operator->() const;
	T& operator*();
	T* operator->();

	operator void*() const { return mPtr; }

protected:
	T* mPtr;
	static std::map<T*, int> sRefCountMap;

	void finalizePointer();
	void initPointer(T* inPtr);
};

template <typename T>
std::map<T*, int> SuperSmartPointer<T>::sRefCountMap;

template <typename T>
SuperSmartPointer<T>::SuperSmartPointer(T* inPtr)
{
	initPointer(inPtr);
}

template <typename T>
SuperSmartPointer<T>::SuperSmartPointer(const SuperSmartPointer<T>& src)
{
	initPointer(src.mPtr);
}

template <typename T>
SuperSmartPointer<T>& 
	SuperSmartPointer<T>::operator=(const SuperSmartPointer<T>& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	finalizePointer();
	initPointer(rhs.mPtr);

	return *this;
}

template <typename T>
SuperSmartPointer<T>::~SuperSmartPointer()
{
	finalizePointer();
}

template<typename T>
void SuperSmartPointer<T>::initPointer(T* inPtr)
{
	mPtr = inPtr;
	if (sRefCountMap.find(mPtr) == sRefCountMap.end()) {  
		sRefCountMap[mPtr] = 1;
	} else {
		sRefCountMap[mPtr]++;
	}
}

template<typename T>
void SuperSmartPointer<T>::finalizePointer()
{
	if (sRefCountMap.find(mPtr) == sRefCountMap.end()) {
		throw std::runtime_error("ERROR: Missing entry in map!");
	}
	sRefCountMap[mPtr]--;
	if (sRefCountMap[mPtr] == 0) {
		// no No more references to this object -- delete it and remove from map
		sRefCountMap.erase(mPtr);
		delete mPtr;
		mPtr = nullptr;
	}
}

template <typename T>
const T* SuperSmartPointer<T>::operator->() const
{
	return mPtr;
}

template <typename T>
const T& SuperSmartPointer<T>::operator*() const
{
	return *mPtr;
}

template <typename T>
T* SuperSmartPointer<T>::operator->() 
{
	return mPtr;
}

template <typename T>
T& SuperSmartPointer<T>::operator*() 
{
	return *mPtr;
}



// Tests follow

class Nothing
{
public:
	Nothing() { sNumAllocations++; }
	virtual ~Nothing() { sNumDeletions++; }

	static int sNumAllocations;
	static int sNumDeletions;
};

int Nothing::sNumAllocations = 0;
int Nothing::sNumDeletions = 0;

int main()
{
	Nothing* myNothing = new Nothing();

	{
		SuperSmartPointer<Nothing> ptr1(myNothing);
		SuperSmartPointer<Nothing> ptr2(myNothing);
	}

	if (Nothing::sNumAllocations != Nothing::sNumDeletions) {
		std::cout << "TEST FAILED: " << Nothing::sNumAllocations <<
			" allocations and " << Nothing::sNumDeletions << 
			" deletions" << std::endl;
	} else {
		std::cout << "TEST PASSED" << std::endl;
	}

	return 0;
}
