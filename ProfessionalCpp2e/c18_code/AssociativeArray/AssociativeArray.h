#include <string>
#include <vector>

class AssociativeArray
{
public:
	AssociativeArray();
	virtual ~AssociativeArray();
	int& operator[](const std::string& key);
	const int& operator[](const std::string& key) const;
protected:
	class Element
	{
	public:
		Element(const std::string& key, int value) :
		  mKey(key), mValue(value) {}
		std::string mKey;
		int mValue;
	};
	std::vector<Element> mData;
};
