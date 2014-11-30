template <typename T>
class SimpleTemplate
{
public:
	SimpleTemplate(T& inObject);

	const T& get() const;
	void set(T& inObject);

protected:
	T& mObject;
};

#include "SimpleTemplate.cpp" // include the implementation!
