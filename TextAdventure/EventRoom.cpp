#include "EventRoom.h"
#include "Common.h"
#include "RecipeBuilder.h"

namespace MilkAndSugar::World
{
	//Constructors
	EventRoom::EventRoom()
	{
		m_eventPrompt = "Start the event.";
		m_eventCompleted = false;
		m_questItemsRequired = 0;
	}
	EventRoom::EventRoom(int nIndex, std::string nName, std::string nEventPrompt, int nQItemReq) : Location(nIndex, nName)
	{
		m_eventPrompt = nEventPrompt;
		m_eventCompleted = false;
		m_questItemsRequired = nQItemReq;
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
	void EventRoom::startEvent(Core::RecipeBuilder nRecipe, Object::Player& nPlayer, Core::Quest nQuest, std::string eventType)
	{
		UI::Text eventText;

		if (eventType == "Tea") 
		{
			nRecipe.teaBuilder(nPlayer, nQuest);
		}
		if (eventType == "John1")
		{
			
		}
		
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