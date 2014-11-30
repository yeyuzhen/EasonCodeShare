#include <string>
#include <stdexcept>
#include <map>

using std::string;

class NameDB
{
public:
	NameDB(const string& nameFile) throw (std::invalid_argument);

	int getNameRank(const string& name) const;
	int getAbsoluteNumber(const string& name) const;

protected:
	std::map<string, int> mNames;

	bool nameExistsAndIncrement(const string& name);
	void addNewName(const string& name);
};
