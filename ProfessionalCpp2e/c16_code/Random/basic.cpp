// basic.cpp
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(1, 99);
	cout << dist(eng) << endl;

	return 0;
}

