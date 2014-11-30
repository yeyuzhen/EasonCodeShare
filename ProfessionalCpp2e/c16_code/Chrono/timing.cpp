// timing.cpp
#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

int main()
{
	// Get the start time
	auto start = system_clock::now();
	// Execute code that you want to time
	double d = 0;
	for (int i = 0; i < 1000000; ++i)
		d += sqrt(sin(i) * cos(i));
	// Get the end time and calculate the difference
	auto end = system_clock::now();
	auto diff = end - start;
	// Convert the difference into milliseconds and print on the console
	cout << duration<double, milli>(diff).count() << "ms" << endl;

	return 0;
}
