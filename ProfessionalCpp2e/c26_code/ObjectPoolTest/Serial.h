// Serial.h
#include <cstddef>

class Serial
{
public:
	Serial();
	size_t getSerialNumber() const;

protected:
	static size_t sNextSerial;
	size_t mSerialNumber;
};

