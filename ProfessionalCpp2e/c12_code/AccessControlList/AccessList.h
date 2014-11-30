#include <set>
#include <string>
#include <list>
#include <initializer_list>

using std::set;
using std::string;
using std::list;
using std::initializer_list;

class AccessList
{
public:
	// Default constructor
	AccessList() {}
	// Constructor to support C++11 uniform initialization.
	AccessList(const initializer_list<string>& initlst);

	// Adds the user to the permissions list.
	void addUser(const string& user);

	// Removes the user from the permissions list.
	void removeUser(const string& user);

	// Returns true if the user is in the permissionns list.
	bool isAllowed(const string& user) const;

	// Returns a list of all the users who have permissions.
	list<string> getAllUsers() const;

protected:
	set<string> mAllowed;
};
