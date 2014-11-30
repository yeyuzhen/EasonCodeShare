#include <stdexcept>
#include <iostream>

void throwIf(bool inShouldThrow) throw (std::runtime_error) 
{
	if (inShouldThrow) {
		throw std::runtime_error("Here's my exception");
	}
}

int main()
{
	try {
		throwIf(false); // doesn't throw
		throwIf(true);  // throws!
	} catch (const std::runtime_error& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
