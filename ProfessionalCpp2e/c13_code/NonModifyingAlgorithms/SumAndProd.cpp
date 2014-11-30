#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

// Function template to populate a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true) {
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		cont.push_back(num);
	}
}

class SumAndProd : public unary_function<int, void>
{
public:
	SumAndProd() : sum(0), prod(1) {}
	void operator()(int elem);

	// make sum and prod public for easy access
	int sum;
	int prod;
};

void SumAndProd::operator()(int elem)
{
	sum += elem;
	prod *= elem;
}

int main()
{
	vector<int> myVector;
	populateContainer(myVector);

	SumAndProd func;
	func = for_each(myVector.cbegin(), myVector.cend(), func);
	cout << "The sum is " << func.sum << endl;
	cout << "The product is " << func.prod << endl;

	return 0;
}
