#include "Location.h"
#include <iostream>


Location::Location()
{
	this->name = "Empty Location";
	this->description = "This location is empty.";
	this->flavorText = "";
}

//Parameters: Name, Description, 
Location::Location(string nName, string nDesc)
{
	name = nName;
	description = nDesc;
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
	return this->connectionsVector;
}

//Returns the number of connections in the vector
int Location::getNumConnections()
{
	return this->connectionsVector.size();
}

//Returns a specific connection from the vector based on index
Location* Location::getConnection(int index)
{
	return this->connectionsVector[index];
}

void Location::addConnection(Location* nlocation)
{
	this->connectionsVector.push_back(nlocation);
}

void Location::removeConnection(int index)
{
	this->connectionsVector.erase(this->connectionsVector.begin() + index);
}

void Location::outputConnections()
{
	for (int i = 0; i < this->connectionsVector.size(); i++)
	{
		cout << i + 1 << ") " << this->connectionsVector[i]->getName() << endl;
	}
}
