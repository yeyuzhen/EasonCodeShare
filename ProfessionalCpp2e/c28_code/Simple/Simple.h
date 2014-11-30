#ifndef _simple_h_
#define _simple_h_

// A simple class that illustrates class definition syntax.
class Simple {

public:
	Simple();                       // Constructor
	virtual ~Simple();              // Destructor

	virtual void publicMethod();    // Public method

	int mPublicInteger;             // Public data member

protected:
	int mProtectedInteger;          // Protected data member
	static const int mConstant = 2; // Protected constant
	static int sStaticInt;          // Protected static data member

private:
	int mPrivateInteger;            // Private data member

	// disallow assignment and pass-by-value
	Simple(const Simple& src);
	Simple& operator=(const Simple& rhs);
};

#endif 
