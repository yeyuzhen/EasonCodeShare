// shared_ptr_file.cpp
#include <iostream>
#include <memory>
#include <cstdio>
using namespace std;

void CloseFile(FILE* filePtr)
{
    if (filePtr == nullptr)
        return;
    fclose(filePtr);
    cout << "File closed." << endl;
}

int main()
{
    shared_ptr<FILE> filePtr(fopen("data.txt", "w"), CloseFile);
	if (filePtr == nullptr) {
		cerr << "Error opening file." << endl;
	} else {
		cout << "File opened." << endl;
	    // Use filePtr
	}
    return 0;
}
