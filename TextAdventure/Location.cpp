#include "Location.h"
#include <iostream>

Location::Location()
{
	this->name = "Empty Location";
	this->connections = {};
}

Location::Location(string nName, bool keyReq) : Location()
{
    this->name = nName;
	this->keyRequired = keyReq;
}

string Location::getName()
{
	if (keyRequired)
		return this->name + " [Locked]";
	else
		return this->name;
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