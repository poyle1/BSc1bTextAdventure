#pragma once
#include <string>
#include <iostream>
 
namespace GameObject
{
    class Player;
    class Quest;
    class RecipeBuilder;

      struct RequirementDetails {
            std::string itemName;
            int amount = 0;
            bool collected = false;
        };

    class Event
    {
    private:
        std::string m_name;
        std::string m_prompt;
        bool m_completed;
        std::string m_functionID;

        bool m_requirement;
      
        RequirementDetails m_eventRequirements;

    public:

        Event();
        Event(std::string nID, std::string nName, std::string nPrompt, bool nReq);
        Event(std::string nID, std::string nName, std::string nPrompt, bool nReq, std::string nRequItemName, int nRequItemAmount);

        std::string getName() const;
        void setName(std::string nName);
        std::string getPrompt() const;
        void setPrompt(std::string nPrompt);
        bool isCompleted() const;
        void setCompleted(bool nCompleted);

        bool hasRequirement() const;
        std::string getReqItemName() const;
        void setReqItemName(std::string nName);
        int getReqItemAmount() const;
        void setReqItemAmount(int nAmount);
        bool getCollected() const;
        void setCollected(bool nCollected);

        bool canStartEvent(Player& nPlayer, std::string nItem) const;
        void runFunction(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest);
        void teaBuilder(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest);
        void talkToJohn(Player& nPlayer, Quest& nQuest);
        void fillKettle(Player& nPlayer);

        //void startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest);
    };
}