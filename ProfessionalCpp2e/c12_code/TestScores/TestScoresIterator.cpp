#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<double> doubleVector;
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
    for (vector<double>::iterator iter = doubleVector.begin();
        iter != doubleVector.end(); ++iter) {
        *iter /= max;
        cout << *iter << " ";
    }
	cout << endl;
/*
	// Using C++11 auto keyword
	for (auto iter = doubleVector.begin();
        iter != doubleVector.end(); ++iter) {
        *iter /= max;
        cout << *iter << " ";
    }
	cout << endl;
*/
/*
	// Using C++11 Range Based for loop
    for (auto& d : doubleVector) {
        d /= max;
        cout << d << " ";
    }
	cout << endl;
*/
    return 0;
}
