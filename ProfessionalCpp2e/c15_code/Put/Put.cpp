#include <iostream>

using namespace std;

void rawPutChar(const char* data, int charIndex)
{
	cout.put(data[charIndex]);
}

int main()
{
	char* mystr = "hello";
	rawPutChar(mystr, 1);

	return 0;
}
