#pragma once
#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Location; //Forward declaration

struct Door
{
	Location* targetLocation;
	bool locked;
	string requiredKeyID;
};

class Location
{
private:
	//attributes
	string name;
	string inspectText;

	vector<Item*> items; //Vector of pointers to items in the location
	vector<Door> doors; //Tracks where doors lead to, and if they are locked.

public:
	//Constructors
	Location();
	Location(string nName);

	//Door logic
	void addDoor(Location* targetLoc, bool locked, string keyID);
	bool isLocked(int index); //Checks if a specific connection is locked, used to check if the player can move to a location before moving there
	bool unlockDoor(int index, const vector <Item*>& playerInventory); //Checks the player's inventory for the correct key and unlocks the location if found

	//Getters and setters
	string getName();
	string getInspectText();
	void setInspectText(string nText);

	//Items
	bool hasItems();
	vector<Item*>& getItems();
	void addItem(Item* nItem);
	void removeItems();

	//Connection Logic
	//RENAME THESE TO DOORS
	int getNumConnections(); //Used to check user input when selecting a location to move to
	Location* getConnection(int index); //Used to get the connecting location based on user input
	void outputConnections();
};