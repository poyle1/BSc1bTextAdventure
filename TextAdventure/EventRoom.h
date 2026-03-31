#pragma once
#include "Location.h"
#include <iostream>

namespace MilkAndSugar::World
{
    class EventRoom : public Location
    {
    private:
        std::string m_eventPrompt;
        bool m_eventCompleted;

    public:
        // Constructors
        EventRoom();
        EventRoom(int nIndex, std::string nName, std::string nEventPrompt);

        // Event Logic
        virtual bool canStartEvent();
        virtual std::string getEventPrompt();
        virtual void startEvent();
    };
}
