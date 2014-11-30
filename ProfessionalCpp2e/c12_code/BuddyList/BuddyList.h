#include <map>
#include <string>
#include <list>

using std::multimap;
using std::string;
using std::list;

class BuddyList
{
public:
	BuddyList();

	// Adds buddy as a friend of name.
	void addBuddy(const string& name, const string& buddy);

	// Removes buddy as a friend of name
	void removeBuddy(const string& name, const string& buddy);

	// Returns true if buddy is a friend of name, false otherwise.
	bool isBuddy(const string& name, const string& buddy) const;

	// Retrieves a list of all the friends of name.
	list<string> getBuddies(const string& name) const;

protected:
	multimap<string, string> mBuddies;
};
