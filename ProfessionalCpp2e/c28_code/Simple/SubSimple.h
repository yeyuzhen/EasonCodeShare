#ifndef _subsimple_h_
#define _subsimple_h_

#include "Simple.h"

// A subclass of the Simple class
class SubSimple : public Simple
{
public:
	SubSimple();                  // Constructor
	virtual ~SubSimple();         // Destructor 

	virtual void publicMethod();  // Overridden method

	virtual void anotherMethod(); // Added method
};

#endif
