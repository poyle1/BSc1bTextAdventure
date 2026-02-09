#pragma once
#include <vector>
#include <string>

using namespace std;

//Syntax for inheritance
//#include "Location.h"
//class location: public Location
class Location
{
private:
	string name;
	string description;
	string flavorText;
	string entryText;
	//Tree structure of locations, with each location having a vector of pointers to other locations
	//Made with a vector of pointers
	vector <Location*> connections;

public:
	Location();
	Location(string nName, string nDesc);

	string getName();
	void setName(string nName);
	string getDescription();
	void setDescription(string nDesc);
	string getFlavorText();
	void setFlavorText(string nFlavorText);
	string getEntryText();
	void setEntryText(string nEntryText);

	vector<Location*> getConnections(); //vector<Card> getHand();
	int getNumConnections(); ////int getHandSize();
	

	Location* getConnection(int index); //Card getCard(int index);

	void addConnection(Location* nLocation); //void addCard(Card new_card);
	void removeConnection(int index); //void removeCard(int index);

	void outputConnections(); //void outputHand();


	
};

