#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Location
{
private:
	string name;
	string description;
	vector <Location*> connections;

	//Location* prevLocation;
	//Location* nextLocation;

public:
	Location();
	Location(string nName, string nDesc);

	string getName();
	string getDescription();
	void setName(string nName);
	void setDescription(string nDesc);


	void addConnection(Location* nlocation);

	//Location* getNextLoc();
	//Location* getPrevLoc();

	bool hasNextLoc();
	bool hasPrevLoc();

	
};

