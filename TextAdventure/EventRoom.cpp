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
	}
	EventRoom::EventRoom(int nIndex, std::string nName, std::string nEventPrompt) : Location(nIndex, nName)
	{
		m_eventPrompt = nEventPrompt;
		m_eventCompleted = false;
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
	void EventRoom::startEvent(Core::RecipeBuilder nRecipe, Object::Player& nPlayer, Core::Quest nQuest)
	{
		nRecipe.teaBuilder(nPlayer, nQuest);

		m_eventCompleted = true;
	}
}