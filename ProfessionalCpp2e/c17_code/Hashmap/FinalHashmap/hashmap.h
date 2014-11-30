#include <cstddef>
#include <vector>
#include <list>
#include <stdexcept>
#include <iterator> 
#include <string>
#include <initializer_list>
#include <algorithm>
using std::vector;
using std::list;
using std::invalid_argument;
using std::string;
using std::pair;
using std::initializer_list;
using std::for_each;

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

template <typename Key, typename T, typename Compare, typename Hash>
class hashmap;


// HashIterator class definition
template<typename Key, typename T, typename Compare, typename Hash>
class HashIterator : public std::iterator<std::bidirectional_iterator_tag,
	pair<const Key, T>>
{
	// The hashmap class needs access to protected members of the HashIterator
	friend class hashmap<Key, T, Compare, Hash>;
public:
	HashIterator(); // bi-directional iterators must supply default ctor
	HashIterator(size_t bucket,
		typename list<pair<const Key, T>>::iterator listIt,
		const hashmap<Key, T, Compare, Hash>* inHashmap);

	pair<const Key, T>& operator*() const;

	// Return type must be something to which -> can be applied.
	// Return a pointer to a pair<const Key, T>, to which the compiler will
	// apply -> again
	pair<const Key, T>* operator->() const;
	HashIterator<Key, T, Compare, Hash>& operator++();
	const HashIterator<Key, T, Compare, Hash> operator++(int);

	HashIterator<Key, T, Compare, Hash>& operator--();
	const HashIterator<Key, T, Compare, Hash> operator--(int);

	// don't need to define a copy constructor or operator= because the
	// default behavior is what we want.

	// don't need destructor because the default behavior
	// (not deleting mHashmap) is what we want.

	// The following are ok as member functions because we don't support
	// comparisons of different types to this one
	bool operator==(const HashIterator& rhs) const;
	bool operator!=(const HashIterator& rhs) const;

protected:
	size_t mBucket;
	typename list<pair<const Key, T>>::iterator mIt;
	const hashmap<Key, T, Compare, Hash>* mHashmap;

	// Helper methods for operator++ and operator--
	void increment();
	void decrement();
};

template <typename Key, typename T, typename Compare = std::equal_to<Key>,
	typename Hash = DefaultHash<Key>>
class hashmap
{
public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef pair<const Key, T> value_type;
	typedef Compare key_compare;
	typedef pair<const Key, T>& reference;
	typedef const pair<const Key, T>& const_reference;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;
	typedef HashIterator<Key, T, Compare, Hash> iterator;
	typedef HashIterator<Key, T, Compare, Hash> const_iterator;

	// Required class definition for associative containers
	class value_compare :
		public std::binary_function<value_type, value_type, bool>
	{
		friend class hashmap<Key, T, Compare, Hash>;
	public:
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}
	};

	// The iterator class needs access to protected members of the hashmap
	friend class HashIterator<Key, T, Compare, Hash>;

	// Iterator methods
	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
	const_iterator cbegin() const;		// For C++11
	const_iterator cend() const;		// For C++11


	// Constructors
	// throws invalid_argument if the hash object specifies an illegal
	// number of buckets.   
	explicit hashmap(const Compare& comp = Compare(),
		const Hash& hash = Hash()) throw(invalid_argument);

	template <class InputIterator>
	hashmap(InputIterator first, InputIterator last,
		const Compare& comp = Compare(), const Hash& hash = Hash())
		throw(invalid_argument);

	// destructor, copy constructor, move constructor,
	// copy assignment operator and move assignment operator
	~hashmap();
	hashmap(const hashmap<Key, T, Compare, Hash>& src);
	hashmap(hashmap<Key, T, Compare, Hash>&& src);        // C++11
	hashmap<Key, T, Compare, Hash>& operator=(const hashmap<
		Key, T, Compare, Hash>& rhs);
	hashmap<Key, T, Compare, Hash>& operator=(hashmap<
		Key, T, Compare, Hash>&& rhs);  // C++11

	// C++11 initializer list constructor
	hashmap(initializer_list<value_type> il, const Compare& comp = Compare(),
		const Hash& hash = Hash()) throw(invalid_argument);
	// C++11 initializer list assignment operator
	hashmap<Key, T, Compare, Hash>& operator=(initializer_list<value_type> il);

	// Size methods
	bool empty() const;
	size_type size() const;
	size_type max_size() const;

	// element insert methods
	T& operator[] (const key_type& x);
	pair<iterator, bool> insert(const value_type& x);
	iterator insert(iterator position, const value_type& x);
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last);
	void insert(initializer_list<value_type> il);         // C++11

	// C++11 emplace methods
	pair<iterator, bool> emplace(value_type&& x);
	iterator emplace_hint(iterator hint, value_type&& x);

	// element delete methods
	void erase(iterator position);
	size_type erase(const key_type& x);
	void erase(iterator first, iterator last);


	// other modifying utilities
	void swap(hashmap<Key, T, Compare, Hash>& hashIn);

	void clear();

	// access methods for STL conformity
	key_compare key_comp() const;
	value_compare value_comp() const;

	// Lookup methods
	iterator find(const key_type& x);
	const_iterator find(const key_type& x) const;
	size_type count(const key_type& x) const;

protected:
	typedef list<value_type> ListType;
	typename ListType::iterator
		findElement(const key_type& x, size_t& bucket) const;

	// A pointer to a vector is used so that swap() can
	// be implemented in constant time.
	vector<ListType>* mElems;
	size_type mSize;
	Compare mComp;
	Hash mHash;
};

#include "hashmap.cpp"
