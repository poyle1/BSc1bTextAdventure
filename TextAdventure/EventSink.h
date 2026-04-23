#pragma once
#include "Event.h"

#include <string>
#include <iostream>

namespace GameObject
{
    class Player;
    class Quest;
    class RecipeBuilder;

    class EventSink : public Event
    {
    private:

    public:
        EventSink();
        EventSink(std::string nID, std::string nName, std::string nPrompt, bool nReq, std::string nRequItemName, int nRequItemAmount);

        void eventFunction(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest) override;
    };
}