#include "Serial.h"

Serial::Serial()
{
	mSerialNumber = sNextSerial++;
}

size_t Serial::getSerialNumber() const
{
	return mSerialNumber;
}

size_t Serial::sNextSerial = 0;
