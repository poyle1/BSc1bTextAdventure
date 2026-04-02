#include "EventRoom.h"
#include "Common.h"

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
	void EventRoom::startEvent()
	{
		std::cout << "Event started: " << m_eventPrompt << std::endl;

		m_eventCompleted = true;
	}
}