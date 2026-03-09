#include "Location.h"
#include <iostream>

///Constructors
Location::Location()
{
	this->name = "A location";
}

Location::Location(string nName)
{
    this->name = nName;
}

//Door logic
void Location::addDoor(Location* targetLoc, bool locked, string keyID)
{
	Door newDoor;
	newDoor.targetLocation = targetLoc;
	newDoor.locked = locked;
	newDoor.requiredKeyID = keyID;
	this->doors.push_back(newDoor);
}

bool Location::isLocked(int index)
{
	if (index >= 0 && index < this->doors.size())
	{
		return this->doors[index].locked;
	}
	return false; //safety check
}

bool Location::unlockDoor(int index, const vector<Item*>& playerInventory)
{
	if (index < 0 || index >= this->doors.size()) {
		return false; //Invalid index safety check
	}
	for (Item* i : playerInventory)
	{
		if (i->getKeyID() == this->doors[index].requiredKeyID)
		{
			this->doors[index].locked = false;
			cout << "You use the " << i->getName() << " to unlock the door." << endl;
			return true;
		}
	}
	return false; //No matching key found in inventory
}

//Getters and setters
string Location::getName()
{
		return this->name;
}

string Location::getInspectText()
{
	return this->inspectText;
}

void Location::setInspectText(string nText)
{
	this->inspectText = nText;
}

//Items
bool Location::hasItems()
{
	if (this->locItems.empty())
	{
		return false;
	}
	return true;
}

vector<Item*>& Location::getItems()
{
	return this->locItems;
}

void Location::addItem(Item* nItem)
{
	this->locItems.push_back(nItem);
}

void Location::removeItems()
{
	this->locItems.clear();
}

//Door/connection Logic
int Location::getNumDoors()
{
	return this->doors.size();
}

Location* Location::getDoor(int index)
{
	if (index >= 0 && index < this->doors.size()) 
	{
		return this->doors[index].targetLocation; //Returns the target location of the door at the specified index
	}
	return nullptr; //safety check
}

void Location::outputDoors() //Outputs the target location of each door relative to the current location.
{							 //Used to display a full list of available locations that the player can travel to.
	for (int i = 0; i < this->doors.size(); i++)
	{
		cout << i + 1 << ") " << doors[i].targetLocation->getName();
		if (doors[i].locked) {
			cout << " [LOCKED]";
		}
		cout << endl;
	}
}

bool Location::allItemsCollected(int totalIng, const vector<Item*>& playerInventory)
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
