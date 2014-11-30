//InitializerLists.cpp
#include <iostream>
#include <initializer_list>

using namespace std;

int makeSum(initializer_list<int> lst)
{
	int total = 0;
	for (auto iter = lst.begin(); iter != lst.end(); ++iter)
		total += (*iter);
	return total;
}

int main()
{
	cout << makeSum({1,2,3}) << endl;

	return 0;
}
