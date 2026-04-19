//#pragma once
//#include "Location.h"
//
//#include <string>
//#include <iostream>
//
//namespace GameObject
//{
//	class Player;
//	class Quest;
//	class RecipeBuilder;
//
//    class EventRoom : public Location
//    {
//    private:
//        std::string m_eventPrompt;
//		std::string m_eventType;
//        bool m_eventCompleted;
//		int m_questItemsRequired;
//		bool m_isEventRoom;
//
//    public:
//        EventRoom();
//        EventRoom(int nIndex, std::string nName, std::string nDescription, std::string nEventPrompt, int nQItemReq, std::string nEventType);
//
//       // bool canStartEvent(Inventory& playerInventory, int reqAmount) override;
//        //std::string getEventPrompt() override;
//		std::string getEventType() const;
//        void setEventType(std::string nType);
//       // void startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest) override;
//		bool getIsEventRoom() const override;
//        void setIsEventRoom(bool nIsEventRoom);
//
//        int getQuestItemsRequired() const;
//		void setQuestItemsRequired(int reqItems);
//    };
//}