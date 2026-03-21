#pragma once
#include "Location.h"
#include <iostream>

class EventRoom : public Location
{
private:
    string eventPrompt;
    bool eventCompleted;

public:
    // Constructors
    EventRoom();
    EventRoom(int nIndex, string nName, string nEventPrompt);

    // Event Logic
    virtual bool canStartEvent();
    virtual string getEventPrompt();
    virtual void startEvent();
};