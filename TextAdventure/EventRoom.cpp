//#include "EventRoom.h"
//
//#include <string>
//#include <iostream>
//
//#include "Utility.h"
//#include "RecipeBuilder.h"
//#include "Text.h"
//#include "Player.h"
//#include "Quest.h"
//
//namespace GameObject
//{
//	EventRoom::EventRoom()
//	{
//		m_eventPrompt = "Start the event.";
//		m_eventCompleted = false;
//		m_questItemsRequired = 0;
//		m_eventType = "";
//		m_isEventRoom = true;
//		m_searched = false;
//	}
//	EventRoom::EventRoom(int nIndex, std::string nName, std::string nDescription, std::string nEventPrompt, int nQItemReq, std::string nEventType)
//		: Location(nIndex, nName, nDescription)
//	{
//		m_eventPrompt = nEventPrompt;
//		m_eventCompleted = false;
//		m_questItemsRequired = nQItemReq;
//		m_eventType = nEventType;
//		m_isEventRoom = true;
//		m_searched = false;
//	}
//	bool EventRoom::canStartEvent(Inventory& playerInventory, int reqAmount)
//	{
//		if (playerInventory.hasReqQuestItems(reqAmount) && !m_eventCompleted)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	std::string EventRoom::getEventPrompt()
//	{
//		if (m_eventPrompt.empty())
//		{
//			return "ERROR MISSING EVENT PROMPT";
//		}
//		return m_eventPrompt;
//	}
//	std::string EventRoom::getEventType() const
//	{
//		return m_eventType;
//	}
//	void EventRoom::setEventType(std::string nType)
//	{
//		m_eventType = nType;
//	}
//
//	m_eventType is set via ifstream to determine what the EventRoom activates.
//	void EventRoom::startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
//	{
//		The 'Tea' event advances the quest and starts the
//		 RecipeBuilder minigame if the player has quest items
//		 >= the amount of steps in the recipe
//		if (m_eventType == "Tea")
//		{
//			if (nPlayer.getInventory().getQuestItemTotal() < nRecipe.getRecipeSteps())
//			{
//				std::cout << "You don't have all " << nRecipe.getRecipeSteps() << " ingredients needed! Come back when you have collected them all." << std::endl;
//				UI::pauseAndFlush();
//				return;
//			}
//			nQuest.advanceState(Quest::Achieved, nPlayer);
//			nRecipe.teaBuilderMkII(nPlayer, nQuest);
//			return;
//		}
//		The 'John' event advances the quest and delivers dialogue to 
//		 the player based on the current quest state
//		else if (m_eventType == "John")
//		{
//			if (nQuest.getState() == Quest::Unknown)
//			{
//				UI::Text::getInstance().johnDialogue1(nPlayer);
//				nQuest.advanceState(Quest::Accepted, nPlayer);
//				UI::pauseAndFlush();
//			} 
//			else if (nQuest.getState() == Quest::Accepted)
//			{
//				UI::Text::getInstance().johnDialogue2(nPlayer);
//				UI::pauseAndFlush();
//			}
//			else if (nQuest.getState() == Quest::Achieved)
//			{
//				for (int i = 0; i < nPlayer.getInventory().getInventory().size(); i++)
//				{
//					if (nPlayer.getInventory().getItemViaIndex(i)->isQuestItem())
//					{
//						if (nPlayer.getInventory().getItemViaIndex(i)->getScoreValue() <= 15) //Bad ending, 15 or less score
//						{
//							std::cout << "You pass the tea over to John." << std::endl;
//							UI::Text::getInstance().johnDialogueBadEnding(nPlayer);
//							nQuest.setResult(Quest::Bad);
//						} 
//						else if //Neutral Ending, between 15-19 score
//							(nPlayer.getInventory().getItemViaIndex(i)->getScoreValue() > 15 && nPlayer.getInventory().getItemViaIndex(i)->getScoreValue() < 19)
//						{
//							std::cout << "You pass the tea over to John." << std::endl;
//							UI::Text::getInstance().johnDialogueNeutralEnding(nPlayer);
//							nQuest.setResult(Quest::Neutral);
//						}
//						else //Good Ending, 19-30 score
//						{
//							std::cout << "You pass the tea over to John." << std::endl;
//							UI::Text::getInstance().johnDialogueGoodEnding(nPlayer);
//							nQuest.setResult(Quest::Good);
//						}
//					}
//				}
//				nQuest.advanceState(Quest::Completed, nPlayer);
//				UI::pauseAndFlush();
//			}
//		}
//		else if (m_eventType == "FillKettle")
//		{
//
//		}
//	}
//	
//	bool EventRoom::getIsEventRoom() const
//	{
//		return m_isEventRoom;
//	}
//	void EventRoom::setIsEventRoom(bool nIsEventRoom)
//	{
//		m_isEventRoom = nIsEventRoom;
//	}
//	int EventRoom::getQuestItemsRequired() const
//	{
//		return m_questItemsRequired;
//	}
//	void EventRoom::setQuestItemsRequired(int reqItems)
//	{
//		m_questItemsRequired = reqItems;
//	}
//}