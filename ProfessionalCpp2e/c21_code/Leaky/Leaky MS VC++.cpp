#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif  // _DEBUG

#include <iostream>

using namespace std;

class Simple 
{
public:
	Simple() { mIntPtr = new int(); }
	~Simple() { delete mIntPtr; }

	void setIntPtr(int inInt) { *mIntPtr = inInt; }

protected:
	int* mIntPtr;
};

void doSomething(Simple*& outSimplePtr)
{
	outSimplePtr = new Simple(); // BUG! Doesn't delete the original
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Simple* simplePtr = new Simple(); // allocate a Simple object

	doSomething(simplePtr);

	delete simplePtr; // only cleans up the second object

	return 0;
}
