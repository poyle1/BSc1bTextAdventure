#include "EventRoom.h"
#include "Common.h"
#include "RecipeBuilder.h"
#include "Text.h"
#include "Player.h"
#include "Quest.h"
namespace MilkAndSugar::World
{
	//Constructors
	EventRoom::EventRoom()
	{
		m_eventPrompt = "Start the event.";
		m_eventCompleted = false;
		m_questItemsRequired = 0;
		m_eventType = "";
		m_isEventRoom = true;
		m_dialogue = nullptr;
	}
	EventRoom::EventRoom(int nIndex, std::string nName, std::string nEventPrompt, int nQItemReq, std::string nEventType) : Location(nIndex, nName)
	{
		m_eventPrompt = nEventPrompt;
		m_eventCompleted = false;
		m_questItemsRequired = nQItemReq;
		m_eventType = nEventType;
		m_isEventRoom = true;
		m_dialogue = nullptr;
	}

	//Event logic
	bool EventRoom::canStartEvent(MilkAndSugar::World::Inventory& playerInventory, int reqAmount)
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
	void EventRoom::startEvent(Core::RecipeBuilder& nRecipe, Object::Player& nPlayer, Core::Quest& nQuest)
	{
		if (m_eventType == "Tea") 
		{
			nRecipe.teaBuilder(nPlayer, nQuest);
		}
		if (m_eventType == "John")
		{
			if (m_dialogue != nullptr)
			{
				if (nQuest.getState() == Core::Quest::Unknown)
				{
					m_dialogue->johnDialogue1(nPlayer);
					nQuest.advanceState(Core::Quest::Accepted, nPlayer);
				}
				//if (nQuest.getState() == Core::Quest::Accepted)
				//{
				//}
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