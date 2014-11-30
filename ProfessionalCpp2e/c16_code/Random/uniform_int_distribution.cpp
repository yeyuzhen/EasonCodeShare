#include <random>
#include <time.h>
#include <functional>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	const unsigned int DIST_START = 1;
	const unsigned int DIST_END = 99;
	const unsigned int ITERATIONS = 1000000;

	// Uniform Mersenne Twister
	mt19937 eng(static_cast<unsigned long>(time(nullptr)));
	uniform_int_distribution<int> dist(DIST_START, DIST_END);
	auto gen = bind(dist, eng);
	map<int, int> m;
	for (unsigned int i = 0; i < ITERATIONS; ++i) {
		int rnd = gen();
		++(m[rnd]);
	}

	// Write to a CSV file
	ofstream of("res.csv");
	for (unsigned int i = DIST_START; i <= DIST_END; ++i) {
		of << i << ",";
		auto res = m.find(i);
		of << (res != m.end() ? res->second : 0) << endl;
	}

	return 0;
}
