#include <iostream>
using namespace std;

#include "greeting.h"
#include "name.h"

int main(int argc, char *argv[])
{
	cout << Greeting() << ", " << Name() << endl;
	return 0;
}
