/**
 * Note to reader:
 * 
 * These classes are a great starting point for testing out 
 * the edge cases of multiple inheritance. For example, you
 * can start with these classes to build a diamond hierarchy 
 * and turn it into a virtual base class.
 */

#include <iostream>

using namespace std;

class Dog
{
public:
  virtual void bark() { cout << "woof!" << endl; }
  virtual void eat() { cout << "The dog has eaten." << endl; }
};

class Bird
{
public:
  virtual void chirp() { cout << "chirp!" << endl; }
  virtual void eat() { cout << "The bird has eaten." << endl; }
};

class DogBird : public Dog, public Bird
{
	//void eat() { Dog::eat(); }  // Explicitly call Dog's version of eat()
};

int main()
{
  DogBird myConfusedAnimal;

  myConfusedAnimal.bark();
  myConfusedAnimal.chirp();
  //myConfusedAnimal.eat();                  // BUG! Ambiguous call to method eat()
  static_cast<Dog>(myConfusedAnimal).eat();  // Slices, calling Dog::eat()
  myConfusedAnimal.Dog::eat();               // Calls Dog::eat()

  return 0;
} 
