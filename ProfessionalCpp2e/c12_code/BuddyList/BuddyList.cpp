#include "BuddyList.h"

using namespace std;

BuddyList::BuddyList()
{
}

void BuddyList::addBuddy(const string& name, const string& buddy)
{
	// Make sure this buddy isn't already there. We don't want
	// to insert an identical copy of the key/value pair.
	if (!isBuddy(name, buddy)) {
		mBuddies.insert({name, buddy}); // Using C++11 initializer_list
	}
}

void BuddyList::removeBuddy(const string& name, const string& buddy)
{
	// Pre-C++11
	//multimap<string, string>::iterator start, end;

	// Obtain the beginning and end of the range of elements with
	// key 'name'. Use both lower_bound() and upper_bound() to demonstrate
	// their use. Otherwise, you could just call equal_range().
	auto start = mBuddies.lower_bound(name);
	auto end = mBuddies.upper_bound(name); 

	// Iterate through the elements with key 'name' looking
	// for a value 'buddy'
	for (; start != end; ++start) {
		if (start->second == buddy) {
			// We found a match! Remove it from the map.
			mBuddies.erase(start);
			break;
		}
	}
}

bool BuddyList::isBuddy(const string& name, const string& buddy) const
{
	// Pre-C++11
	//multimap<string, string>::const_iterator start, end;

	// Obtain the beginning and end of the range of elements with
	// key 'name'.
	auto start = mBuddies.lower_bound(name);
	auto end = mBuddies.upper_bound(name);

	// Iterate through the elements with key 'name' looking
	// for a value 'buddy'. If there are no elements with key 'name',
	// start equals end, so the loop body doesn't execute.
	for (; start != end; ++start) {
		if (start->second == buddy) {
			// We found a match!
			return true;
		}
	}
	// No matches
	return false;
}

list<string> BuddyList::getBuddies(const string& name) const
{
	// Obtain the pair of iterators marking the range containing
	// elements with key 'name'.
	auto its = mBuddies.equal_range(name);

	// Pre-C++11
	//pair<multimap<string, string>::const_iterator,
	//  multimap<string, string>::const_iterator> its;
	//its = mBuddies.equal_range(name);

	// Create a list with all names in the range (all buddies of name).
	list<string> buddies;
	for (; its.first != its.second; ++its.first) {
		buddies.push_back(its.first->second);
	}

	return buddies;
}
