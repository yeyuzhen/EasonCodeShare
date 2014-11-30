#include <vector>
#include <iostream>

using namespace std;

int main()
{
	int arr[10];     // standard C-style array
	vector<int> vec; // STL vector

	// Initialize each element of the array to the value of its index.
	for (int i = 0; i < 10; i++) {
		arr[i] = i;
	}

	// Insert the contents of the array into the end of the vector.
	vec.insert(vec.end(), arr, arr + 10);

	// print the contents of the vector
	for (auto& i : vec) {
		cout << i << " ";
	}

	return 0;
}
