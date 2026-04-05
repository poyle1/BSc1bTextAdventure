#pragma once
#include "Location.h"
#include <iostream>
#include "RecipeBuilder.h"

namespace MilkAndSugar::World
{
    class EventRoom : public Location
    {
    private:
        std::string m_eventPrompt;
        bool m_eventCompleted;
		int m_questItemsRequired;

    public:
        //Constructors
        EventRoom();
        EventRoom(int nIndex, std::string nName, std::string nEventPrompt, int nQItemReq);

        //Event Logic
        bool canStartEvent(MilkAndSugar::World::Inventory& playerInventory, int reqAmount) override;
        std::string getEventPrompt() override;
        void startEvent(MilkAndSugar::Core::RecipeBuilder nRecipe, MilkAndSugar::Object::Player& nPlayer, MilkAndSugar::Core::Quest nQuest, std::string eventType) override;

        int getQuestItemsRequired() const;
		void setQuestItemsRequired(int reqItems);
    };
}
