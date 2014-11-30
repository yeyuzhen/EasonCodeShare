#include <string>
#include <stdexcept>
#include <vector>
#include <utility>

using std::string;

class NameDB
{
public:
	// Reads the list of baby names in nameFile to populate the database.
	// Throws invalid_argument if nameFile cannot be opened or read.
	NameDB(const string& nameFile) throw (std::invalid_argument);

	// Returns the rank of the name (1st, 2nd, etc).
	// Returns –1 if the name is not found.
	int getNameRank(const string& name) const;
	// Returns the number of babies with this name.
	// Returns –1 if the name is not found.
	int getAbsoluteNumber(const string& name) const;

protected:
	std::vector<std::pair<string, int>> mNames;

	// Helper methods
	bool nameExists(const string& name) const;
	void incrementNameCount(const string& name);
	void addNewName(const string& name);
};
