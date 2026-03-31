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
	bool EventRoom::canStartEvent()
	{
		return !m_eventCompleted;
	}
	std::string EventRoom::getEventPrompt()
	{
		return m_eventPrompt;
	}
	void EventRoom::startEvent()
	{
		std::cout << "Event started: " << m_eventPrompt << std::endl;

		m_eventCompleted = true;

	}
}