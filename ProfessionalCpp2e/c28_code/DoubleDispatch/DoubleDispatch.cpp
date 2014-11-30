#include <iostream>

using namespace std;

// forward declarations
class Fish;
class Bear;
class Dinosaur;

class Animal
{
public:
	virtual bool eats(const Animal& inPrey) const = 0;

	virtual bool eatenBy(const Bear& inBear) const = 0;
	virtual bool eatenBy(const Fish& inFish) const = 0;
	virtual bool eatenBy(const Dinosaur& inDinosaur) const = 0;
};

class Bear : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const;

	virtual bool eatenBy(const Bear& inBear) const;
	virtual bool eatenBy(const Fish& inFish) const;
	virtual bool eatenBy(const Dinosaur& inDinosaur) const;
};

class Fish : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const;

	virtual bool eatenBy(const Bear& inBear) const;
	virtual bool eatenBy(const Fish& inFish) const;
	virtual bool eatenBy(const Dinosaur& inDinosaur) const;
};

class Dinosaur : public Animal
{
public:
	virtual bool eats(const Animal& inPrey) const;

	virtual bool eatenBy(const Bear& inBear) const;
	virtual bool eatenBy(const Fish& inFish) const;
	virtual bool eatenBy(const Dinosaur& inDinosaur) const;
};


bool Bear::eats(const Animal& inPrey) const 
{
	return inPrey.eatenBy(*this);
}

bool Bear::eatenBy(const Bear& inBear) const 
{ 
	return false; 
}

bool Bear::eatenBy(const Fish& inFish) const 
{ 
	return false; 
}

bool Bear::eatenBy(const Dinosaur& inDinosaur) const 
{ 
	return true;
}


bool Fish::eats(const Animal& inPrey) const 
{
	return inPrey.eatenBy(*this);
}

bool Fish::eatenBy(const Bear& inBear) const 
{ 
	return true; 
}

bool Fish::eatenBy(const Fish& inFish) const 
{ 
	return true; 
}

bool Fish::eatenBy(const Dinosaur& inDinosaur) const 
{ 
	return true;
}


bool Dinosaur::eats(const Animal& inPrey) const 
{
	return inPrey.eatenBy(*this);
}

bool Dinosaur::eatenBy(const Bear& inBear) const 
{ 
	return false; 
}

bool Dinosaur::eatenBy(const Fish& inFish) const 
{ 
	return false; 
}

bool Dinosaur::eatenBy(const Dinosaur& inDinosaur) const 
{ 
	return true;
}

int main()
{
	Fish myFish;
	Bear myBear;
	Dinosaur myDino;

	cout << "Fish eats bear? " << myFish.eats(myBear) << endl;
	cout << "Fish eats dino? " << myFish.eats(myDino) << endl;
	cout << "Dino eats bear? " << myDino.eats(myBear) << endl;
	cout << "Bear eats fish? " << myBear.eats(myFish) << endl;

	return 0;
}
