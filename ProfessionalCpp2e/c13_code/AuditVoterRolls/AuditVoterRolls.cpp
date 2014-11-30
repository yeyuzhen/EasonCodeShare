#include <algorithm>
#include <functional>
#include <map>
#include <list>
#include <iostream>
#include <utility>
#include <string>
#include <set>
using namespace std;

typedef map<string, list<string>> VotersMap;
typedef pair<const string, list<string>> DistrictPair;

// getDuplicates()
//
// Returns a set of all names that appear in more than one list in
// the map.
//
// The implementation generates one large list of all the names from
// all the lists in the map, sorts it, then finds all duplicates
// in the sorted list with adjacent_find().
set<string> getDuplicates(const VotersMap& votersByDistrict)
{
/*	set<string> allNames;
	set<string> duplicates;
	for (auto& district : votersByDistrict) {
		for (auto& name : district.second) {
			if (!allNames.insert(name).second)
				duplicates.insert(name);
		}
	}
	return duplicates;
*/
	// Collect all the names from all the lists into one big list
	list<string> allNames;
	for (auto& district : votersByDistrict) {
		allNames.insert(allNames.end(), district.second.begin(), district.second.end());
	}

	// sort the list -- use the list version, not the general algorithm,
	// because the list version is faster
	allNames.sort();

	// Now it's sorted, all duplicate names will be next to each other.
	// Use adjacent_find() to find instances of two or more identical names
	// next to each other.
	// Loop until adjacent_find() returns the end iterator.
	set<string> duplicates;
	for (auto lit = allNames.cbegin(); lit != allNames.cend(); ++lit) {
		lit = adjacent_find(lit, allNames.cend());
		if (lit == allNames.cend()) {
			break;
		}
		duplicates.insert(*lit);
	}

	return duplicates;
}

// auditVoterRolls
//
// Expects a map of string/list<string> pairs keyed on district names
// and containing lists of all the registered voters in those districts.
//
// Removes from each list any name on the convictedFelons list and
// any name that is found on any other list.
void auditVoterRolls(VotersMap& votersByDistrict,
	const list<string>& convictedFelons)
{
	// get all the duplicate names
	set<string> toRemove = getDuplicates(votersByDistrict);

	// combine the duplicates and convicted felons -- we want
	// to remove names on both lists from all voter rolls
	toRemove.insert(convictedFelons.cbegin(), convictedFelons.cend());

	// Now remove all the names we need to remove using
	// nested lambda expressions and the remove-erase-idiom
	for_each(votersByDistrict.begin(), votersByDistrict.end(),
		[&toRemove](DistrictPair& district) {
			auto it = remove_if(district.second.begin(), district.second.end(),
				[&](const string& name) {
					return (toRemove.count(name) > 0);
				});
			district.second.erase(it, district.second.end());
		});
}

int main()
{
	// Initialize map using uniform initialization
	VotersMap voters = {
		{"Orange", {"Amy Aardvark", "Bob Buffalo", "Charles Cat", "Dwayne Dog"}},
		{"Los Angeles", {"Elizabeth Elephant", "Fred Flamingo", "Amy Aardvark"}},
		{"San Diego", {"George Goose", "Heidi Hen", "Fred Flamingo"}}
	};

	list<string> felons = {"Bob Buffalo", "Charles Cat"};

	// Local lambda expression to print a district
	auto printDistrict = [](const DistrictPair& district) {
		cout << district.first << ":";
		for (auto& str : district.second)
			cout << " {" << str << "}";
		cout << endl;
	};

	cout << "Before Audit:" << endl;
	for_each(voters.cbegin(), voters.cend(), printDistrict);
	cout << endl;
	auditVoterRolls(voters, felons);
	cout << "After Audit:" << endl;
	for_each(voters.cbegin(), voters.cend(), printDistrict);
	cout << endl;

	return 0;
}
