#include "Location.h"
#include "Utility.h"
#include "Inventory.h"
#include <iostream>
#include <vector>
using namespace Utility;

///Constructors
Location::Location()
{
	m_index = NULL;
	m_name = "A location";
}

Location::Location(const int nIndex, std::string nName)
{
	m_index = nIndex;
	m_name = nName;
}

//Door logic
void Location::addDoor(Location* nDestination, bool nLocked, std::string nKeyID)
{
	Door newDoor;
	newDoor.destination = nDestination;
	newDoor.locked = nLocked;
	newDoor.requiredKeyID = nKeyID;
	m_doors.push_back(newDoor);
}

bool Location::isLocked(int index)
{
	if (index >= 0 && index < m_doors.size())
	{
		return m_doors[index].locked;
	}
	return false; //safety check
}

bool Location::unlockDoor(int index, std::vector<Item*>& playerInventory)
{
	if (index < 0 || index >= m_doors.size()) {
		return false; //Invalid index safety check
	}
	for (int i = 0; i < playerInventory.size(); i++)
	{
		if (playerInventory[i]->getKeyID() == m_doors[index].requiredKeyID)
		{
			m_doors[index].locked = false;
			cout << "You use the " << playerInventory[i]->getName() << " to unlock the door." << endl;
			playerInventory.erase(playerInventory.begin() + i);
			return true; //Exit loop
		}
	}
	return false; //No matching key found in inventory
}

//Getters and setters
std::string Location::getName() const
{
	return m_name;
}

std::string Location::getInspectText() const
{
	return m_inspectText;
}

void Location::setInspectText(std::string nText)
{
	m_inspectText = nText;
}

int Location::getIndex() const
{
	if (!m_index) {
		return -1;
	}
	return m_index;
}

//Items
bool Location::hasItems()
{
	if (m_locItems.empty())
	{
		return false;
	}
	return true;
}

void Location::itemCheck()
{
	if (m_locItems.empty())
	{
		cout << "There are no items in this room." << endl;
	}
	else
	{
		cout << "There may be items in this room." << endl;
	}
}

std::vector<Item*>& Location::getItems()
{
	return m_locItems;
}

void Location::addItem(Item* nItem)
{
	m_locItems.push_back(nItem);
}

void Location::removeItems()
{
	m_locItems.clear();
}

void Location::investigateRoom(int& collectedIng, Inventory& playerInventory)
{
	//cout << getInspectText() << endl;
	if (!hasItems())
	{
		std::cout << "There doesn't seem to be anything useful in here." << std::endl;
		return;
	}
	std::cout << "You look around and grab: " << std::endl;
	for (Item* i : m_locItems)
	{
		std::cout << "-" << i->getName() << std::endl;
		playerInventory.addItem(i);
	}
	removeItems();
}

//Door/connection Logic
int Location::getNumDoors()
{
	return m_doors.size();
}

Location* Location::getDoor(int index)
{
	if (index >= 0 && index < m_doors.size())
	{
		return m_doors[index].destination; //Returns the target location of the door at the specified index
	}
	return nullptr; //safety check
}

void Location::outputDoors() //Outputs the target location of each door relative to the current location.
{							 //Used to display a full list of available locations that the player can travel to.
	for (int i = 0; i < m_doors.size(); i++)
	{
		cout << i + 1 << ") Enter the: " << m_doors[i].destination->getName();
		if (m_doors[i].locked) {
			cout << " [LOCKED]";
		}
		cout << endl;
	}
}

// Displays the entry text of the location when the player enters it
void Location::enterLocation()
{
	cout << "You have entered the " << getName() << "." << endl;
	pauseAndFlush();
}

bool Location::allItemsCollected(int totalIng, std::vector<Item*>& playerInventory)
{
	for (Item* i : playerInventory)
	{
		if (i->isQuestItem())
		{
			totalIng += 1;
		}
	}
	if (totalIng >= 5)
	{
		return true; //If the player has all the quest items, return true
	}
	
	return false; //If the player does not have all the quest items, return false
}

//Event logic
bool Location::canStartEvent()
{
	return false;
}

std::string Location::getEventPrompt()
{
	return std::string("");
}

void Location::startEvent()
{
	return;
}
