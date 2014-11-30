#include <iostream>
#include <cstring>
using namespace std;

static const size_t NOT_FOUND = (size_t)(-1);

template <typename T>
size_t Find(T& value, T* arr, size_t size)
{
	cout << "original" << endl;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i; // found it; return the index
		}
	}
	return NOT_FOUND; // Failed to find it; return NOT_FOUND
}

size_t Find(char*& value, char** arr, size_t size)
{
	cout << "overload" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // found it; return the index
		}
	}
	return NOT_FOUND; // Failed to find it; return NOT_FOUND
}

int main()
{
	char* word = "two";
	char* arr[] = {"one", "two", "three", "four"};
	size_t sizeArr = sizeof(arr) / sizeof(arr[0]);
	size_t res;
	res = Find<char*>(word, arr, sizeArr); // Calls the Find template with T=char*
	res = Find(word, arr, sizeArr);        // Calls the Find non-template function.
	if (res != NOT_FOUND)
		cout << res << endl;
	else
		cout << "Not found" << endl;

	return 0;
}
