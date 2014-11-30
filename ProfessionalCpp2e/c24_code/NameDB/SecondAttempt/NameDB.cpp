#include "NameDB.h"

#include <fstream>

using namespace std;

// Reads the names from the file and populates the database.
// The database is a map associating names with their frequency.
NameDB::NameDB(const string& nameFile) throw (invalid_argument)
{
	// Open the file and check for errors
	ifstream inFile(nameFile.c_str());
	if (!inFile) {
		throw invalid_argument("Unable to open file");
	}

	// Read the names one at a time.
	string name;
	while (inFile >> name) {
		// Look up the name in the database so far.
		if (!nameExistsAndIncrement(name)) {
			// If the name exists in the database, the
			// method incremented it, so we just continue.
			// We get here if it didn't exist, in which case
			// we add it with a count of 1.
			addNewName(name);
		}
	}
	inFile.close();
}

// Returns true if the name exists in the database, false
// otherwise. If it finds it, it increments it.
bool NameDB::nameExistsAndIncrement(const string& name)
{
	// Find the name in the map
	auto res = mNames.find(name);
	if (res != mNames.end()) {
		res->second++;
		return true;
	}
	return false;
}

// Adds a new name to the database.
void NameDB::addNewName(const string& name)
{
	mNames[name] = 1;
}

// Returns the rank of the name.
// First looks up the name to obtain the number of babies with that name.
// Then iterates through all the names, counting all the names with a higher
// count than the specified name. Returns that count as the rank.
int NameDB::getNameRank(const string& name) const
{
	int num = getAbsoluteNumber(name);

	// Check if we found the name
	if (num == -1) {
		return -1;
	}

	// Now count all the names in the map that have 
	// count higher than this one. If no name has a higher count,
	// this name is rank number 1. Every name with a higher count
	// decreases the rank of this name by 1.
	int rank = 1;
	for (auto it = mNames.cbegin(); it != mNames.cend(); ++it) {
		if (it->second > num) {
			rank++;
		}
	}

	return rank;
}

// Returns the count associated with this name.
int NameDB::getAbsoluteNumber(const string& name) const
{
	auto res = mNames.find(name);
	if (res != mNames.end()) {
		return res->second;
	}

	return -1;
}
