#include <queue>
#include <stdexcept>
#include <memory>

using std::queue;
using std::shared_ptr;

// template class ObjectPool
//
// Provides an object pool that can be used with any class that provides a
// default constructor.
//
// The object pool constructor creates a pool of objects, which it hands out
// to clients when requested via the acquireObject() method. When a client is
// finished with the object it calls releaseObject() to put the object back
// into the object pool.
//
// The constructor and destructor on each object in the pool will be called only
// once each for the lifetime of the program, not once per acquisition and release.
//
// The primary use of an object pool is to avoid creating and deleting objects
// repeatedly. The object pool is most suited to applications that use large 
// numbers of objects for short periods of time.
//
// For efficiency, the object pool doesn't perform sanity checks.
// It expects the user to release every acquired object exactly once.
// It expects the user to avoid using any objects that he or she has released.
template <typename T>
class ObjectPool
{
public:
	// Creates an object pool with chunkSize objects.
	// Whenever the object pool runs out of objects, chunkSize
	// more objects will be added to the pool. The pool only grows:
	// objects are never removed from the pool (freed), until
	// the pool is destroyed.
	//
	// Throws invalid_argument if chunkSize is 0.
	// Throws bad_alloc if allocation fails.
	ObjectPool(size_t chunkSize = kDefaultChunkSize)
		throw(std::invalid_argument, std::bad_alloc);

	// Reserves an object for use. Clients must not free the object!
	shared_ptr<T> acquireObject();

	// Returns the object to the pool. Clients must not use the object after
	// it has been returned to the pool.
	void releaseObject(shared_ptr<T> obj);

protected:
	// mFreeList stores the objects that are not currently in use by clients.
	queue<shared_ptr<T>> mFreeList;

	size_t mChunkSize;
	static const size_t kDefaultChunkSize = 10;

	// Allocates mChunkSize new objects and adds them to mFreeList.
	void allocateChunk();

private:
	// Prevent assignment and pass-by-value
	ObjectPool(const ObjectPool<T>& src);
	ObjectPool<T>& operator=(const ObjectPool<T>& rhs);
};

template<typename T>
const size_t ObjectPool<T>::kDefaultChunkSize;

template <typename T>
ObjectPool<T>::ObjectPool(size_t chunkSize) throw(std::invalid_argument,
	std::bad_alloc)
{
	if (chunkSize == 0) {
		throw std::invalid_argument("chunk size must be positive");
	}
	mChunkSize = chunkSize;
	// Create mChunkSize objects to start
	allocateChunk();
}

// Allocates mChunkSize new objects.
template <typename T>
void ObjectPool<T>::allocateChunk()
{
	for (size_t i = 0; i < mChunkSize; ++i) {
		mFreeList.push(std::make_shared<T>());
	}
}

template <typename T>
shared_ptr<T> ObjectPool<T>::acquireObject()
{
	if (mFreeList.empty()) {
		allocateChunk();
	}
	auto obj = mFreeList.front();
	mFreeList.pop();
	return obj;
}

template <typename T>
void ObjectPool<T>::releaseObject(shared_ptr<T> obj)
{
	mFreeList.push(obj);
}
