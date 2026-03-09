#pragma once
#include <vector>
#include <string>
#include "Item.h"
using namespace std;

class Location; //Forward declaration

struct Door
{
	Location* targetLocation = nullptr;
	bool locked = false;
	string requiredKeyID = "";
};

class Location
{
private:
	//attributes
	string name;
	string inspectText;
	
	vector<Item*> locItems; //Vector of pointers to items in the location
	vector<Door> doors; //Each location has a list of doors, 

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

	//Door/Connection Logic
	//RENAME THESE TO DOORS
	int getNumDoors(); //Used to check user input when selecting a location to move to
	Location* getDoor(int index); //Used to get the connecting location based on user input
	void outputDoors();

	bool allItemsCollected(int totalIng, const vector <Item*>& playerInventory);
};