// function_callback.cpp
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void process(const vector<int>& vec, function<void(int)> f)
{
	for (auto& i : vec)
		f(i);
}

void print(int num)
{
	cout << num << "  ";
}

int main()
{
	vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i);

	process(vec, print);
	cout << endl;

	int sum = 0;
	process(vec, [&sum](int num){sum += num;});
	cout << "sum = " << sum << endl;
	
	return 0;
}

