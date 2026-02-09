#include "Location.h"
#include <iostream>


Location::Location()
{
	this->name = "Empty Location";
	this->description = "This location is empty.";
	this->connections = {};


	this->flavorText = "";
}
//syntax for constructor with parameters
//Location::Location(string parameter1, int parameter2, bool parameter3) : Otherclass(parameter1)
//{
// //this->memberVariable1 = parameter1;
//}


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
