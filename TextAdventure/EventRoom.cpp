#include "EventRoom.h"

//Constructors
EventRoom::EventRoom()
{
	this->eventPrompt = "Start the event.";
	this->eventCompleted = false;
}
EventRoom::EventRoom(int nIndex, std::string nName, std::string nEventPrompt) : Location(nIndex, nName)
{
	this->eventPrompt = nEventPrompt;
	this->eventCompleted = false;
}

//Event logic
bool EventRoom::canStartEvent()
{
	return !this->eventCompleted;
}
std::string EventRoom::getEventPrompt()
{
	return this->eventPrompt;
}
void EventRoom::startEvent()
{
	std::cout << "Event started: " << this->eventPrompt << std::endl;

	eventCompleted = true;

}
