#pragma once
#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Location
{
private:
	string name;
	string inspectText;
	bool keyRequired;
	string doorID; //ID for the door to this location, used to check if the player has the correct key to unlock it
	vector <Location*> connections; //Tree structure of locations using a vector of pointers
	//connectionLockedFlags {false, true}


	vector<Item*> items; //Vector of pointers to items in the location
	

public:
	Location();
	Location(string nName, bool keyReq, string nDoorID);

	string getName();
	string getInspectText();
	void setInspectText(string nText);

	bool isLocked(int connectionIndex);
	bool unlocked(vector <Item*> playerInventory); //Checks the player's inventory for the correct key and unlocks the location if found
	string getDoorID();


	bool hasItems();
	vector<Item*>& getItems();
	void addItem(Item* nItem);
	void removeItems();

	vector<Location*> getConnections(); //Gets the vector of connections, used for outputting the list of available locations to the player
	int getNumConnections(); //Gets the number of connections, used for  checking user input when selecting a location to move to
	Location* getConnection(int index); //Card getCard(int index);
	void addConnection(Location* nLocation); //void addCard(Card new_card);
	void outputConnections(); //void outputHand();
};

