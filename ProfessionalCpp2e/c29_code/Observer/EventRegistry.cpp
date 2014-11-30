// Implements the EventRegistry class

#include "EventRegistry.h"
#include <iostream>

using namespace std;

// Define the static map.
map<int, vector<Listener*>> EventRegistry::sListenerMap;

void EventRegistry::registerListener(int inMessage, Listener* inListener)
{
	// Chapter 12 explains std::map. Note that if you specify a key
	// using [] to access it, and there is not yet an entry in the map for
	// that key, a new entry is created.
	sListenerMap[inMessage].push_back(inListener);
}

void EventRegistry::handleMessage(int inMessage)
{ 
    // Check to see if the message has *any* listeners. This check is required
    // because otherwise, accessing sListenerMap[inMessage] would create
    // a new entry when it’s not yet in the map. See Chapter 12.
	if (sListenerMap.find(inMessage) == sListenerMap.end())
		return;
	for (auto iter = sListenerMap[inMessage].begin();
		iter != sListenerMap[inMessage].end(); ++iter) {
			(*iter)->handleMessage(inMessage);
	}
}
