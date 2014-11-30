// TestListener.h

#ifndef TEST_LISTENER_H
#define TEST_LISTENER_H

#include "Listener.h"

class TestListener : public Listener
{
    public:
        TestListener();
        void handleMessage(int inMessage);
        bool bMessage0Received;
        bool bUnknownMessageReceived;
};

#endif
