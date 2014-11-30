#include <iostream>
#include <vector>
#include <thread>
#include <functional>

void func(int& counter)
{
	for (int i = 0; i < 10000; ++i) {
		++counter;
	}
}

int main()
{
	int counter = 0;
	std::vector<std::thread> threads;

	for (int i = 0; i < 10; ++i) {
		threads.push_back(std::thread{func, std::ref(counter)});
	}

	for (auto& t : threads) {
		t.join();
	}

	std::cout << "Result = " << counter << std::endl;

	return 0;
}
