#include "Event.h"

#include <string>
#include <iostream>

#include "Utility.h"
#include "RecipeBuilder.h"
#include "Text.h"
#include "Player.h"
#include "Quest.h"
#include "Inventory.h"

namespace GameObject
{
	Event::Event()
	{
		m_name = "Default Event";
		m_prompt = "Start the event";
		m_completed = false;
		m_requiresItems = false;
		m_requiredItemName = "";
		m_requiredItemAmount = 0;
		m_requiredItemCollected = false;
	}
	Event::Event(std::string nName, std::string nPrompt, bool nRequiresItems, std::string nRequiresItemName, int nRequiresItemAmount)
	{
		m_name = nName;
		m_prompt = nPrompt;
		m_completed = false;
		m_requiresItems = nRequiresItems;
		m_requiredItemName = nRequiresItemName;
		m_requiredItemAmount = nRequiresItemAmount;
		m_requiredItemCollected = false;
	}
	bool Event::canStartEvent(Inventory& playerInventory, std::string nItem)
	{
		if (!m_requiresItems)
		{
			return true;
		}
		else
		{
			if (playerInventory.hasItem(nItem) < m_requiredItemAmount)
			{
				std::cout << "You need " << m_requiredItemAmount << " " << nItem << "s" << std::endl;
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

//std::string EventRoom::getEventPrompt()
//{
//	if (m_eventPrompt.empty())
//	{
//		return "ERROR MISSING EVENT PROMPT";
//	}
//	return m_eventPrompt;
//}
//std::string EventRoom::getEventType() const
//{
//	return m_eventType;
//}
//void EventRoom::setEventType(std::string nType)
//{
//	m_eventType = nType;
//}
//
////m_eventType is set via ifstream to determine what the EventRoom activates.
//void EventRoom::startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
//{
//	//The 'Tea' event advances the quest and starts the
//	// RecipeBuilder minigame if the player has quest items
//	// >= the amount of steps in the recipe
//	if (m_eventType == "Tea")
//	{
//		if (nPlayer.getInventory().getQuestItemTotal() < nRecipe.getRecipeSteps())
//		{
//			std::cout << "You don't have all " << nRecipe.getRecipeSteps() << " ingredients needed! Come back when you have collected them all." << std::endl;
//			UI::pauseAndFlush();
//			return;
//		}
//		nQuest.advanceState(Quest::Achieved, nPlayer);
//		nRecipe.teaBuilderMkII(nPlayer, nQuest);
//		return;
//	}
//	//The 'John' event advances the quest and delivers dialogue to 
//	// the player based on the current quest state
//	else if (m_eventType == "John")
//	{
//		if (nQuest.getState() == Quest::Unknown)
//		{
//			UI::Text::getInstance().johnDialogue1(nPlayer);
//			nQuest.advanceState(Quest::Accepted, nPlayer);
//			UI::pauseAndFlush();
//		}
//		else if (nQuest.getState() == Quest::Accepted)
//		{
//			UI::Text::getInstance().johnDialogue2(nPlayer);
//			UI::pauseAndFlush();
//		}
//		else if (nQuest.getState() == Quest::Achieved)
//		{
//			for (int i = 0; i < nPlayer.getInventory().getInventory().size(); i++)
//			{
//				if (nPlayer.getInventory().getItem(i)->isQuestItem())
//				{
//					if (nPlayer.getInventory().getItem(i)->getScoreValue() <= 15) //Bad ending, 15 or less score
//					{
//						std::cout << "You pass the tea over to John." << std::endl;
//						UI::Text::getInstance().johnDialogueBadEnding(nPlayer);
//						nQuest.setResult(Quest::Bad);
//					}
//					else if //Neutral Ending, between 15-19 score
//						(nPlayer.getInventory().getItem(i)->getScoreValue() > 15 && nPlayer.getInventory().getItem(i)->getScoreValue() < 19)
//					{
//						std::cout << "You pass the tea over to John." << std::endl;
//						UI::Text::getInstance().johnDialogueNeutralEnding(nPlayer);
//						nQuest.setResult(Quest::Neutral);
//					}
//					else //Good Ending, 19-30 score
//					{
//						std::cout << "You pass the tea over to John." << std::endl;
//						UI::Text::getInstance().johnDialogueGoodEnding(nPlayer);
//						nQuest.setResult(Quest::Good);
//					}
//				}
//			}
//			nQuest.advanceState(Quest::Completed, nPlayer);
//			UI::pauseAndFlush();
//		}
//	}
//	else if (m_eventType == "FillKettle")
//	{
//
//	}
//}
//
//bool EventRoom::getIsEventRoom() const
//{
//	return m_isEventRoom;
//}
//void EventRoom::setIsEventRoom(bool nIsEventRoom)
//{
//	m_isEventRoom = nIsEventRoom;
//}
//int EventRoom::getQuestItemsRequired() const
//{
//	return m_questItemsRequired;
//}
//void EventRoom::setQuestItemsRequired(int reqItems)
//{
//	m_questItemsRequired = reqItems;
//}
//}