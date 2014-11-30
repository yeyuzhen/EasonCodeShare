// Throws invalid_argument if numBuckets is illegal
template <typename T>
DefaultHash<T>::DefaultHash(size_t numBuckets) throw (invalid_argument)
{
	if (numBuckets <= 0) {
		throw invalid_argument("numBuckets must be > 0");
	}
	mNumBuckets = numBuckets;
}

// Uses the division method for hashing.
// Treats the key as a sequence of bytes, sums the ASCII
// values of the bytes, and mods the total by the number
// of buckets.
template <typename T>
size_t DefaultHash<T>::hash(const T& key) const
{
	size_t bytes = sizeof(key);
	size_t res = 0;
	for (size_t i = 0; i < bytes; ++i) {
		unsigned char b = *((unsigned char*)&key + i);
		res += b;
	}
	return (res % mNumBuckets);
}

// Throws invalid_argument if numBuckets is illegal
DefaultHash<string>::DefaultHash(size_t numBuckets) throw (invalid_argument)
{
	if (numBuckets <= 0) {
		throw invalid_argument("numBuckets must be > 0");
	}
	mNumBuckets = numBuckets;
}

// Uses the division method for hashing after summing the
// ASCII values of all the characters in key.
size_t DefaultHash<string>::hash(const string& key) const
{
	size_t sum = 0;
	for (size_t i = 0; i < key.size(); i++) {
		sum += (unsigned char)key[i];
	}
	return (sum % mNumBuckets);
}

// Construct mElems with the number of buckets.
template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::hashmap(
	const Compare& comp, const Hash& hash) throw(invalid_argument) :
mSize(0), mComp(comp), mHash(hash)
{
	if (mHash.numBuckets() <= 0) {
		throw invalid_argument("Number of buckets must be positive");
	}
	mElems = new vector<ListType>(mHash.numBuckets());
}

template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::~hashmap()
{
	delete mElems;
	mElems = nullptr;
	mSize = 0;
}

template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::hashmap(const hashmap<
	Key, T, Compare, Hash>& src) :
mSize(src.mSize), mComp(src.mComp), mHash(src.mHash)
{
	// Don't need to bother checking if numBuckets is positive, because
	// we know src checked.

	// Use the vector copy constructor
	mElems = new vector<ListType>(*(src.mElems));
}

// C++11 move constructor
template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>::hashmap(hashmap<Key, T, Compare, Hash>&& src)
{
	// move ownership
	mElems = src.mElems;
	src.mElems = nullptr;
	mSize = src.mSize;
	src.mSize = 0;
	mComp = src.mComp;
	mHash = src.mHash;
}


template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>& hashmap<Key, T, Compare, Hash>::operator=(
	const hashmap<Key, T, Compare, Hash>& rhs)
{
	// check for self-assignment
	if (this != &rhs) {
		delete mElems;
		mSize = rhs.mSize;
		mComp = rhs.mComp;
		mHash = rhs.mHash;
		// Don't need to bother checking if numBuckets is positive, because
		// we know rhs checked.

		// Use the vector copy constructor
		mElems = new vector<ListType>(*(rhs.mElems));
	}
	return *this;
}

// C++11 move assignment operator
template <typename Key, typename T, typename Compare, typename Hash>
hashmap<Key, T, Compare, Hash>& hashmap<Key, T, Compare, Hash>::operator=(
	hashmap<Key, T, Compare, Hash>&& rhs)
{
	// check for self-assignment
	if (this != &rhs) {
		delete mElems;

		// move ownership
		mElems = rhs.mElems;
		rhs.mElems = nullptr;
		mSize = rhs.mSize;
		rhs.mSize = 0;
		mComp = rhs.mComp;
		mHash = rhs.mHash;
	}
	return *this;
}

template <typename Key, typename T, typename Compare, typename Hash>
typename list<pair<const Key, T>>::iterator
	hashmap<Key, T, Compare, Hash>::findElement(const key_type& x, size_t& bucket) const
{
	// hash the key to get the bucket
	bucket = mHash.hash(x);

	// Look for the key in the bucket
	for (auto it = (*mElems)[bucket].begin();
		it != (*mElems)[bucket].end(); ++it) {
			if (mComp(it->first, x)) {
				return it;
			}
	}
	return (*mElems)[bucket].end();
}

template <typename Key, typename T, typename Compare, typename Hash>
typename hashmap<Key, T, Compare, Hash>::value_type*
	hashmap<Key, T, Compare, Hash>::find(const key_type& x)
{
	size_t bucket;
	// Use the findElement() helper
	auto it = findElement(x, bucket);
	if (it == (*mElems)[bucket].end()) {
		// we didn't find the element -- return nullptr
		return nullptr;
	}
	// We found the element. Return a pointer to it.
	return &(*it);
}

template <typename Key, typename T, typename Compare, typename Hash>
T& hashmap<Key, T, Compare, Hash>::operator[] (const key_type& x)
{
	// Try to find the element. If it doesn't exist, add a new element.
	value_type* found = find(x);
	if (found == nullptr) {
		insert(make_pair(x, T()));
		found = find(x);
	}
	return found->second;
}

template <typename Key, typename T, typename Compare, typename Hash>
void hashmap<Key, T, Compare, Hash>::insert(const value_type& x)
{
	size_t bucket;
	// Try to find the element
	auto it = findElement(x.first, bucket);

	if (it != (*mElems)[bucket].end()) {
		// The element already exists
		return;
	} else {
		// We didn't find the element, so insert a new one.
		mSize++;
		(*mElems)[bucket].insert((*mElems)[bucket].end(), x);
	}
}

template <typename Key, typename T, typename Compare, typename Hash>
void hashmap<Key, T, Compare, Hash>::erase(const key_type& x)
{
	size_t bucket;

	// First, try to find the element
	auto it = findElement(x, bucket);

	if (it != (*mElems)[bucket].end()) {
		// The element exists -- erase it
		(*mElems)[bucket].erase(it);
		mSize--;
	}
}
