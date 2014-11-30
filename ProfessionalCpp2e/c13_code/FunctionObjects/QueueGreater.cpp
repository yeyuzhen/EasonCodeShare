#include <queue>
#include <functional>
#include <iostream>
using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int> > myQueue;

	myQueue.push(3);
	myQueue.push(4);
	myQueue.push(2);
	myQueue.push(1);

	while (!myQueue.empty()) {
		cout << myQueue.top() <<  " ";
		myQueue.pop();
	}

	return 0;
}
