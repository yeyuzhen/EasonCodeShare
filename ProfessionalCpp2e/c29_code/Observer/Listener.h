// Mix-in class for objects that are able to respond to events

#ifndef LISTENER_H
#define LISTENER_H

class Listener
{
    public:
        virtual void handleMessage(int inMessage) = 0;
};

#endif
