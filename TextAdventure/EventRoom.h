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
		std::string m_eventType;
        bool m_eventCompleted;
		int m_questItemsRequired;
		bool m_isEventRoom;

    public:
        //Constructors
        EventRoom();
        EventRoom(int nIndex, std::string nName, std::string nEventPrompt, int nQItemReq, std::string nEventType);

        //Event Logic
        bool canStartEvent(MilkAndSugar::World::Inventory& playerInventory, int reqAmount) override;
        std::string getEventPrompt() override;
		std::string getEventType() const;
        void startEvent(MilkAndSugar::Core::RecipeBuilder& nRecipe, MilkAndSugar::Object::Player& nPlayer, MilkAndSugar::Core::Quest& nQuest) override;
		bool getIsEventRoom() const override;
        void setIsEventRoom(bool nIsEventRoom);

        int getQuestItemsRequired() const;
		void setQuestItemsRequired(int reqItems);
    };
}
