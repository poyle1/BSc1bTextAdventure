#include "EventRoom.h"

#include <string>
#include <iostream>

#include "Utility.h"
#include "RecipeBuilder.h"
#include "Text.h"
#include "Player.h"
#include "Quest.h"

namespace GameObject
{
	//Constructors
	EventRoom::EventRoom()
	{
		m_eventPrompt = "Start the event.";
		m_eventCompleted = false;
		m_questItemsRequired = 0;
		m_eventType = "";
		m_isEventRoom = true;
		m_searched = false;
	}
	EventRoom::EventRoom(int nIndex, std::string nName, std::string nEventPrompt, int nQItemReq, std::string nEventType) : Location(nIndex, nName)
	{
		m_eventPrompt = nEventPrompt;
		m_eventCompleted = false;
		m_questItemsRequired = nQItemReq;
		m_eventType = nEventType;
		m_isEventRoom = true;
		m_searched = false;
	}

	//Event logic
	bool EventRoom::canStartEvent(Inventory& playerInventory, int reqAmount)
	{
		if (playerInventory.hasReqQuestItems(reqAmount) && !m_eventCompleted)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	std::string EventRoom::getEventPrompt()
	{
		if (m_eventPrompt.empty())
		{
			return "ERROR";
		}
		return m_eventPrompt;
	}
	std::string EventRoom::getEventType() const
	{
		return std::string();
	}
	void EventRoom::startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
	{
		if (m_eventType == "Tea")
		{
			if (nPlayer.getInventory().getQuestItemTotal() < nRecipe.getRecipeSteps())
			{
				std::cout << "You don't have all " << nRecipe.getRecipeSteps() << " ingredients needed! Come back when you have collected them all." << std::endl;
				UI::pauseAndFlush();
				return;
			}
			nQuest.advanceState(Quest::Achieved, nPlayer);
			nRecipe.teaBuilderMkII(nPlayer, nQuest);
			return;
		}
		else if (m_eventType == "John")
		{
			if (nQuest.getState() == Quest::Unknown)
			{
				UI::Text::getInstance().johnDialogue1(nPlayer);
				nQuest.advanceState(Quest::Accepted, nPlayer);
				UI::pauseAndFlush();
			} 
			else if (nQuest.getState() == Quest::Accepted)
			{
				UI::Text::getInstance().johnDialogue2(nPlayer);
				UI::pauseAndFlush();
			}
			else if (nQuest.getState() == Quest::Achieved)
			{
				for (int i = 0; i < nPlayer.getInventory().getItems().size(); i++)
				{
					if (nPlayer.getInventory().getItem(i)->isQuestItem())
					{
						if (nPlayer.getInventory().getItem(i)->getScoreValue() <= 10) //Bad ending
						{
							std::cout << "You pass the tea over to John." << std::endl;
							UI::Text::getInstance().johnDialogueBadEnding(nPlayer);
							nQuest.setResult(Quest::Bad);
						} 
						else if //Neutral Ending
							(nPlayer.getInventory().getItem(i)->getScoreValue() > 10 && nPlayer.getInventory().getItem(i)->getScoreValue() < 19)
						{
							std::cout << "You pass the tea over to John." << std::endl;
							UI::Text::getInstance().johnDialogueNeutralEnding(nPlayer);
							nQuest.setResult(Quest::Neutral);
						}
						else //Good Ending
						{
							std::cout << "You pass the tea over to John." << std::endl;
							UI::Text::getInstance().johnDialogueGoodEnding(nPlayer);
							nQuest.setResult(Quest::Good);
						}
					}
				}
				nQuest.advanceState(Quest::Completed, nPlayer);
				UI::pauseAndFlush();
			}
		}
	}
	
	bool EventRoom::getIsEventRoom() const
	{
		return m_isEventRoom;
	}
	void EventRoom::setIsEventRoom(bool nIsEventRoom)
	{
		m_isEventRoom = nIsEventRoom;
	}
	int EventRoom::getQuestItemsRequired() const
	{
		return m_questItemsRequired;
	}
	void EventRoom::setQuestItemsRequired(int reqItems)
	{
		m_questItemsRequired = reqItems;
	}
}