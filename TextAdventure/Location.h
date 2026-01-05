#pragma once
#include <iostream>

using namespace std;

class Location
{
private:
	string name;
	string description;
	Location* prevLocation;
	Location* nextLocation;

public:
	Location();
	Location(string nName, string nDesc);
	string getName();
	string getDescription();
	void setName(string nName);
	void setDescription(string nDesc);

	void setConnections(Location* prevLoc, Location* nextLoc);
	Location* getNextLoc();
	Location* getPrevLoc();

	bool hasNextLoc();
	bool hasPrevLoc();

};

