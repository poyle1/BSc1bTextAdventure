#include "EventRoom.h"

//Constructors
EventRoom::EventRoom()
{
	this->eventPrompt = "Start the event.";
	this->eventCompleted = false;
}
EventRoom::EventRoom(string nName, string nEventPrompt) : Location(nName)
{
	this->eventPrompt = nEventPrompt;
	this->eventCompleted = false;
}

//Event logic
bool EventRoom::canStartEvent()
{
	return !this->eventCompleted;
}
string EventRoom::getEventPrompt()
{
	return this->eventPrompt;
}
void EventRoom::startEvent()
{
	cout << "Event started: " << this->eventPrompt << endl;

	eventCompleted = true;

}
