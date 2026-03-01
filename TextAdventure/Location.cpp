#include "Location.h"
#include <iostream>

Location::Location()
{
this->name = "Empty Location";
this->keyRequired = false; // Initialize keyRequired to avoid the warning
this->connections = {};
this->doorID = "";
}

Location::Location(string nName, bool keyReq, string nDoorID) : Location()
{
    this->name = nName;
	this->keyRequired = keyReq;
	this->connections = {};
	this->doorID = nDoorID;
}

string Location::getName()
{
	if (keyRequired)
		return this->name + " [Locked]";
	else
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

bool Location::isLocked()
{
	return this->keyRequired;
}

//Cycles through the player's inventory - if an item matches the doorID it returns true.
bool Location::unlocked(vector<Item*> playerInventory)
{
	vector<Item*>::iterator i;
	for (i = playerInventory.begin(); i != playerInventory.end(); ++i)
	{
		if ((*i)->getUnlockID() == this->doorID)
		{
			this->keyRequired = false;
			cout << "You use the " << (*i)->getName() << " to unlock the door." << endl;
			return true;
		}
		else if (i == playerInventory.end() - 1)
		{
			return false;
		}
	}
}

string Location::getDoorID()
{
	return this->doorID;
}

bool Location::hasItems()
{
	return this->items.size();
}

vector<Item*>& Location::getItems()
{
	return this->items;
}

void Location::addItem(Item* nItem)
{
	this->items.push_back(nItem);
}

void Location::removeItems()
{
	this->items.clear();
}

//Returns the entire vector of connections
vector<Location*> Location::getConnections()
{
	return this->connections;
}

//Returns the number of connections in the vector
int Location::getNumConnections()
{
	return this->connections.size();
}

//Returns a specific connection from the vector based on index
//Used to set the location pointer based on user input
Location* Location::getConnection(int index)
{
	return this->connections[index];
}

void Location::addConnection(Location* nlocation)
{
	this->connections.push_back(nlocation);
}

void Location::outputConnections()
{
	for (int i = 0; i < this->connections.size(); i++)
	{
		cout << i + 1 << ") " << this->connections[i]->getName() << endl;
	}
}