#pragma once
#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Location
{
private:
	string name;
	bool keyRequired;
	vector <Location*> connections; //Tree structure of locations using a vector of pointers
	vector<Item*> items; //Vector of pointers to items in the location

public:
	Location();
	Location(string nName, bool keyReq);

	string getName();

	bool isLocked();
	void unlock();

	bool hasItems();
	vector<Item*> getItems();
	void addItem(Item* nItem);
	void removeItem();

	vector<Location*> getConnections(); //Gets the vector of connections, used for outputting the list of available locations to the player
	int getNumConnections(); //Gets the number of connections, used for error checking user input when selecting a location to move to
	Location* getConnection(int index); //Card getCard(int index);
	void addConnection(Location* nLocation); //void addCard(Card new_card);
	void removeConnection(int index); //void removeCard(int index);
	void outputConnections(); //void outputHand();

	
	

};

