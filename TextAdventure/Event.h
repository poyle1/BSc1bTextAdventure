#pragma once
#include <string>
#include <iostream>

#include "Item.h"
namespace GameObject
{
    class Player;
    class Quest;
    class RecipeBuilder;
    class Inventory;

    class Event
    {
    private:
        std::string m_name;
        std::string m_prompt;
        bool m_isCompleted;
        bool m_hasItemRequirement;
        std::string m_requiredItemName;
        int m_requiredItemAmount;
        bool m_isItemCollected;

    public:
        struct Requirement {
            std::string itemName;
            int amount = 0;
            bool isCollected = false;
        };

        Event();
        Event(std::string nName, std::string nPrompt, bool nRequiresItems, std::string nRequiresItemName, int nRequiresItemAmount);

        std::string getName();
        std::string getPrompt();




           std::string

        bool canStartEvent(Inventory& playerInventory, std::string nItem);

        std::string getEventPrompt() ;
        std::string getEventType() const;
        void setEventType(std::string nType);
        void startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest) ;

        int getQuestItemsRequired() const;
        void setQuestItemsRequired(int reqItems);
    };
}