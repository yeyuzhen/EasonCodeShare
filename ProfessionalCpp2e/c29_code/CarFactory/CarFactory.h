// For this example, the Car class is assumed to already exist.
#include "Car.h"

class CarFactory
{
public:
	CarFactory();
	Car* requestCar();
	int getNumCarsInProduction() const;

protected:
	virtual Car* createCar() = 0;

private:
	int mNumCarsInProduction;
};

class FordFactory : public CarFactory
{
protected:
	virtual Car* createCar();
};

class ToyotaFactory : public CarFactory
{
protected:
	virtual Car* createCar();
};
