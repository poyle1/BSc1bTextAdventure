#pragma once
#include "Event.h"

#include <string>
#include <iostream>

namespace GameObject
{
    class Player;
    class Quest;
    class RecipeBuilder;

    class EventJohn : public Event
    {
    private:

    public:
        EventJohn();
        EventJohn(std::string nID, std::string nName, std::string nPrompt, bool nReq);
        EventJohn(std::string nID, std::string nName, std::string nPrompt, bool nReq, std::string nRequItemName, int nRequItemAmount);

        void eventFunction(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest) override;
    };
}
