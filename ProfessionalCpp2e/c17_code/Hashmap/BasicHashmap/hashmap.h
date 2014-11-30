#include <vector>
#include <list>
#include <stdexcept>
using namespace std;

// Any Hash Class must provide two methods: hash() and numBuckets().
template <typename T>
class DefaultHash
{
public:
	// throws invalid_argument if numBuckets is illegal
	DefaultHash(size_t numBuckets = 101) throw (invalid_argument);
	size_t hash(const T& key) const;
	size_t numBuckets() const { return mNumBuckets; }

protected:
	size_t mNumBuckets;
};

// Specialization for strings
template <>
class DefaultHash<string>
{
public:
	// throws invalid_argument if numBuckets is illegal
	DefaultHash(size_t numBuckets = 101) throw (invalid_argument);
	size_t hash(const string& key) const;
	size_t numBuckets() const { return mNumBuckets; }

protected:
	size_t mNumBuckets;
};

template <typename Key, typename T, typename Compare = std::equal_to<Key>,
	typename Hash = DefaultHash<Key>>
class hashmap
{
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef pair<const Key, T> value_type;

	// Constructors
	// throws invalid_argument if the hash object specifies an illegal
	// number of buckets.   
	explicit hashmap(const Compare& comp = Compare(),
		const Hash& hash = Hash()) throw(invalid_argument);

	// destructor, copy constructor, move constructor,
	// copy assignment operator and move assignment operator
	~hashmap();
	hashmap(const hashmap<Key, T, Compare, Hash>& src);
	hashmap(hashmap<Key, T, Compare, Hash>&& src);        // C++11
	hashmap<Key, T, Compare, Hash>& operator=(const hashmap<
		Key, T, Compare, Hash>& rhs);
	hashmap<Key, T, Compare, Hash>& operator=(hashmap<
		Key, T, Compare, Hash>&& rhs);  // C++11

	// inserts the key/value pair x
	void insert(const value_type& x);

	// removes the element with key x, if it exists
	void erase(const key_type& x);

	// find returns a pointer to the element with key x.
	// Returns nullptr if no element with that key exists.
	value_type* find(const key_type& x);

	// operator[] finds the element with key x or inserts an
	// element with that key if none exists yet. Returns a reference to
	// the value corresponding to that key.
	T& operator[] (const key_type& x);

protected:
	typename list<pair<const Key, T>>::iterator
		findElement(const key_type& x, size_t& bucket) const;

	typedef list<value_type> ListType;

	// In this first implementation, it would be easier to use a vector
	// instead of a pointer to a vector, which requires dynamic allocation.
	// However, a pointer to a vector is used so that, in the final
	// implementation, swap() can be implemented in constant time.
	vector<ListType>* mElems;
	size_t mSize;
	Compare mComp;
	Hash mHash;
};

#include "hashmap.cpp"
