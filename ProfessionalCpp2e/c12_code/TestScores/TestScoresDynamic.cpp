#include <vector>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
	vector<double> doubleVector; // create a vector with zero elements
	// Initialize max to smallest number
	double max = numeric_limits<double>::lowest();

	for (size_t i = 0; true; i++) {
		double temp;
		cout << "Enter score " << i + 1 << " (-1 to stop): ";
		cin >> temp;
		if (temp == -1) {
			break;
		}
		doubleVector.push_back(temp);
		if (temp > max) {
			max = temp;
		}
	}

	max /= 100.0;
	for (size_t i = 0; i < doubleVector.size(); i++) { 
		doubleVector[i] /= max;
		cout << doubleVector[i] << " ";
	}
	cout << endl;
	return 0;
}
