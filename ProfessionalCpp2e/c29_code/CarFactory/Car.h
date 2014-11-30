#include <iostream>

class Car
{
public:
	virtual void info() = 0;
};

class Ford : public Car
{
public:
	virtual void info() { std::cout << "Ford" << std::endl; }
};

class Toyota : public Car
{
public:
	virtual void info() { std::cout << "Toyota" << std::endl; }
};
