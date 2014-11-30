#include <cstring>
#include <iostream>

using namespace std;

char* copyString(const char* inString)
{
    //char* result = new char[strlen(inString)];  // BUG! Off by one!
    char* result = new char[strlen(inString) + 1];
	strcpy(result, inString);
    return result;
}

char* appendStrings(const char* inStr1, const char* inStr2, const char* inStr3) 
{
    char* result = new char[strlen(inStr1) + strlen(inStr2) + strlen(inStr3) + 1];
    strcpy(result, inStr1);
    strcat(result, inStr2);
    strcat(result, inStr3);
    return result;
}

int main()
{
	char* str1 = "Hello";
	char* copy = copyString(str1);
	cout << copy << endl;
	delete [] copy;
	copy = nullptr;

	char* str2 = " World";
	char* str3 = "!";
	char* result = appendStrings(str1, str2, str3);
	cout << result << endl;
	delete [] result;
	result = nullptr;

	return 0;
}
