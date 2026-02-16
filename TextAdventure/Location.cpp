#include "Location.h"
#include <iostream>

Location::Location()
{
	this->name = "Empty Location";
	this->description = "This location is empty.";
	this->flavorText = "";
	this->entryText = "";
	this->returnText = "";
	this->connections = {};
	this->visited = false;
	this->locked = false;	
}

Location::Location(string nName, string nDesc, bool nLocked) : Location()
{
    this->name = nName;
    this->description = nDesc;
    this->locked = nLocked;
}


string Location::getName()
{
	return this->name;
}
void Location::setName(string nName)
{
	this->name = nName;
}
string Location::getDescription()
{
	return this->description;
}
void Location::setDescription(string nDesc)
{
	this->description = nDesc;
}

string Location::getFlavorText()
{
	return this->flavorText;
}

void Location::setFlavorText(string nFlavorText)
{
	this->flavorText = nFlavorText;
}

string Location::getEntryText()
{
	return this->entryText;
}

void Location::setEntryText(string nEntryText)
{
	this->entryText = nEntryText;
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
Location* Location::getConnection(int index)
{
	return this->connections[index];
}

void Location::addConnection(Location* nlocation)
{
	this->connections.push_back(nlocation);
}

void Location::removeConnection(int index)
{
	this->connections.erase(this->connections.begin() + index);
}

void Location::outputConnections()
{
	for (int i = 0; i < this->connections.size(); i++)
	{
		cout << i + 1 << ") " << this->connections[i]->getName() << endl;
	}
}

string Location::getDisplayName()
{
	if (locked)
		return this->name + " [Locked]";
	else
		return this->name;
}

bool Location::isLocked()
{
	return this->locked;
}

void Location::setLocked(bool state)
{
	this->locked = state;
}
