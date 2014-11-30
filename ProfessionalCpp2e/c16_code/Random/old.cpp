#include <iostream>
#include <time.h>

using namespace std;

int getRandom(int min, int max)
{
	return (rand() % static_cast<int>(max + 1 - min)) + min;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	cout << rand() << endl;

	cout << getRandom(10, 20) << endl;

	return 0;
}

