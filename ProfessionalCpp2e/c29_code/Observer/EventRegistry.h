// Maintains a directory of Listeners and their corresponding events. Also
// handles transmission of an event to the appropriate Listener.

#ifndef EVENT_REGISTRY_H
#define EVENT_REGISTRY_H

#include "Listener.h"
#include <vector>
#include <map>

class EventRegistry
{
    public:
        static void registerListener(int inMessage, Listener* inListener);
        static void handleMessage(int inMessage);
    protected:
        static std::map<int, std::vector<Listener*>> sListenerMap;
};

#endif
