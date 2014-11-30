#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <vector>

using namespace std;

class PointSequence
{
public:
	PointSequence(initializer_list<double> args)
	{
		if (args.size() % 2 != 0)
			throw invalid_argument("initializer_list should contain even number of elements.");
		for (auto iter = args.begin(); iter != args.end(); ++iter)
			mVecPoints.push_back(*iter);
	}
	void dumpPoints() const
	{
		for (auto citer = mVecPoints.cbegin(); citer != mVecPoints.cend(); citer += 2) {
			cout << "(" << *citer << ", " << *(citer+1) << ")" << endl;
		}
	}
protected:
	vector<double> mVecPoints;
};

int main()
{
	PointSequence p1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
	p1.dumpPoints();
	try {
		PointSequence p2 = {1.0, 2.0, 3.0};
	} catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}

	return 0;
}