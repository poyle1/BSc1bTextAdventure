#pragma once
#include "Location.h"
#include <iostream>

class EventRoom : public Location
{
private:
    std::string eventPrompt;
    bool eventCompleted;

public:
    // Constructors
    EventRoom();
    EventRoom(int nIndex, std::string nName, std::string nEventPrompt);

    // Event Logic
    virtual bool canStartEvent();
    virtual std::string getEventPrompt();
    virtual void startEvent();
};