#include "ObjectPool.h"
#include <iostream>

using namespace std;

class UserRequest
{
public:
	UserRequest() { mID = ++msCount; cout << "ctor " << mID << endl; }
	virtual ~UserRequest() { cout << "dtor " << mID << endl; }

	// Methods to populate the request with specific information.
	// Methods to retrieve the request data.
	// (not shown)

protected:
	int mID;
	static int msCount;
	// data members (not shown)
};
int UserRequest::msCount = 0;

shared_ptr<UserRequest> obtainUserRequest(ObjectPool<UserRequest>& pool)
{
	// Obtain a UserRequest object from the pool
	auto request = pool.acquireObject();

	// populate the request with user input
	// (not shown)

	return request;
}

void processUserRequest(ObjectPool<UserRequest>& pool, shared_ptr<UserRequest> req)
{
	// process the request
	// (not shown)

	// return the request to the pool
	pool.releaseObject(req);
}

int main()
{
	ObjectPool<UserRequest> requestPool(10);

	cout << "Loop starting." << endl;
	for (size_t i = 0; i < 15; ++i) {
		auto req = obtainUserRequest(requestPool);
		processUserRequest(requestPool, req);
	}
	cout << "Loop finished." << endl;

	return 0;
}
