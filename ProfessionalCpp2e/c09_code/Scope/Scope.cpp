#include <iostream>

class Demo
{
public:
	static int get() { return 5; }
};

int get() {	return 10; }

namespace NS
{
	int get() { return 20; }
};

int main()
{
	Demo* pd = new Demo();
	Demo d;
	std::cout << pd->get() << std::endl;    // prints 5
	std::cout << d.get() << std::endl;      // prints 5
	std::cout << NS::get() << std::endl;    // prints 20
	std::cout << Demo::get() << std::endl;  // prints 5
	std::cout << ::get() << std::endl;      // prints 10
	std::cout << get() << std::endl;        // prints 10
	return 0;
}
