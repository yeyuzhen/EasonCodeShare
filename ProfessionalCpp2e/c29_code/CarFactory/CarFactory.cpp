#include "CarFactory.h"

// Initialize the count to zero when the factory is created.
CarFactory::CarFactory() : mNumCarsInProduction(0) {}

// Increment the number of cars in production and return the new car.
Car* CarFactory::requestCar()
{
	mNumCarsInProduction++;
	return createCar();
}

int CarFactory::getNumCarsInProduction() const
{
	return mNumCarsInProduction;
}

Car* FordFactory::createCar()
{
	return new Ford();
}

Car* ToyotaFactory::createCar()
{
	return new Toyota();
}
