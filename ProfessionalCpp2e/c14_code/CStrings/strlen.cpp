#include <cstring>

int main()
{
	char text1[] = "abcdef";
	size_t s1 = sizeof(text1);  // is 7.
	size_t s2 = strlen(text1);  // is 6.
	char * text2 = "abcdef";
	size_t s3 = sizeof(text2);  // is 4
	size_t s4 = strlen(text2);  // is 6

	return 0;
}
