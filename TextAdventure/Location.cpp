#include "Location.h"
#include <vector>
#include <string>
using namespace std;

Location::Location()
{
	this->name = "Empty Location";
	this->description = "This location is empty.";
	//this->prevLocation = nullptr;
	//this->nextLocation = nullptr;
}

//Parameters: Name, Description, 
Location::Location(string nName, string nDesc)
{
	name = nName;
	description = nDesc;
	//prevLocation = nullptr;
	//nextLocation = nullptr;
}

string Location::getName()
{
	return this->name;
}
string Location::getDescription()
{
	return this->description;
}

//Setters not yet needed, but could be useful if the name of a location
//changes during gameplay for whatever reason
void Location::setName(string nName)
{
	this->name = nName;
}
void Location::setDescription(string nDesc)
{
	this->description = nDesc;
}

int Location::getNumConnections()
{
	return this->connections.size();
}

vector<Location*> Location::getConnections()
{
	return this->connections;
}



void Location::getConnection()
{

}

void Location::addConnection(Location* nlocation)
{
	this->connections.push_back(nlocation);
}