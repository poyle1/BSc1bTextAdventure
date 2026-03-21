#include "Location.h"
#include "Utility.h"
#include <iostream>
#include <vector>
using namespace Utility;

///Constructors
Location::Location()
{
	m_name = "A location";
}

Location::Location(int nIndex, string nName)
{
	m_index = nIndex;
	m_name = nName;
}

//Door logic
void Location::addDoor(Location* targetLoc, bool locked, string keyID)
{
	Door newDoor;
	newDoor.targetLocation = targetLoc;
	newDoor.locked = locked;
	newDoor.requiredKeyID = keyID;
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

bool Location::unlockDoor(int index, vector<Item*>& playerInventory)
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
string Location::getName()
{
	return m_name;
}

string Location::getInspectText()
{
	return m_inspectText;
}

void Location::setInspectText(string nText)
{
	m_inspectText = nText;
}

int Location::getIndex()
{
	if (!m_index) {
		return NULL;
	}
	return m_index;
}

//void Location::outputIndex()
//{
//	if (!m_index) {
//		return;
//	}
//	cout << m_index;
//}



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

vector<Item*>& Location::getItems()
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

void Location::investigateRoom(int& collectedIng, vector<Item*>& playerInventory)
{
	cout << getInspectText() << endl;
	if (!hasItems())
	{
		cout << "There doesn't seem to be anything useful in here." << endl;
	}
	else
	{
		cout << "You look around and grab: " << endl;
		for (Item* i : m_locItems)
		{
			cout << "-" << i->getName() << endl;
			playerInventory.push_back(i);
			if (i->isIngredient())
			{
				collectedIng += 1;
			}
		}
		removeItems();
	}
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
		return m_doors[index].targetLocation; //Returns the target location of the door at the specified index
	}
	return nullptr; //safety check
}

void Location::outputDoors() //Outputs the target location of each door relative to the current location.
{							 //Used to display a full list of available locations that the player can travel to.
	for (int i = 0; i < m_doors.size(); i++)
	{
		cout << i + 1 << ") Enter the: " << m_doors[i].targetLocation->getName();
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

bool Location::allItemsCollected(int totalIng,  vector<Item*>& playerInventory)
{
	if (totalIng >= 5)
	{
		return true; //If the player has all the ingredients, return true
	}
	for (Item* i : playerInventory)
	{
		if (i->isIngredient())
		{
			totalIng += 1;
		}
	}
	return false; //If the player does not have all the ingredients, return false
}

//Event logic
bool Location::canStartEvent()
{
	return false;
}

string Location::getEventPrompt()
{
	return string("");
}

void Location::startEvent()
{
	return;
}
