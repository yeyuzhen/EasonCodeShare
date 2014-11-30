#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class MoveableClass
{
public:
	MoveableClass() {
		cout << "Default constructor" << endl;
	}
	MoveableClass(const MoveableClass& src) {
		cout << "Copy constructor" << endl;
	}
	MoveableClass(MoveableClass&& src) {
		cout << "Move constructor" << endl;
	}
	MoveableClass& operator=(const MoveableClass& rhs) {
		cout << "Copy assignment operator" << endl;
		return *this;
	}
	MoveableClass& operator=(MoveableClass&& rhs) {
		cout << "Move assignment operator" << endl;
		return *this;
	}
};

int main()
{
	vector<MoveableClass> vecSource;
	MoveableClass mc;
	vecSource.push_back(mc);
	vecSource.push_back(mc);
	cout << "----" << endl;
	// Copy the elements from vecSource to vecOne
	vector<MoveableClass> vecOne(vecSource.begin(), vecSource.end());
	cout << "----" << endl;
	// Move the elements from vecSource to vecTwo
	vector<MoveableClass> vecTwo(make_move_iterator(vecSource.begin()),
							     make_move_iterator(vecSource.end()));
	cout << "----" << endl;

	return 0;
}
