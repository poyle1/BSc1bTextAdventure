#pragma once
#include <vector>
#include <string>
#include "Item.h"
#include "Inventory.h"

class Location; //Forward declaration

struct Door
{
	Location* destination = nullptr;
	bool locked = false;
	std::string requiredKeyID = "";
};

class Location
{
protected:
	//attributes
	int m_index; //Used to compare locations to doors and keys
	std::string m_name;
	std::string m_inspectText;
	Inventory m_locItems;
	std::vector<Door> m_doors; //Each location has a list of doors, 


public:
	//Constructors
	Location();
	Location(const int nIndex, std::string nName);

	//Getters and setters

	std::string getName() const;
	std::string getInspectText() const;
	void setInspectText(std::string nText);
	int getIndex() const; //gets the index number of the selected location

	//Items

	bool isEmpty();
	void itemCheck();
	//std::vector<Item*>& getItems();
	void addItemToLoc(Item* nItem);
	void removeItems();
	void outputItems();
	bool allItemsCollected(int totalIng, std::vector <Item*>& playerInventory);
	void investigateRoom(Inventory& playerInventory);

	//Door/Connection Logic

	int getNumDoors(); //Used to check user input when selecting a location to move to
	Location* getDoor(int index); //Used to get the connecting location based on user input
	void addDoor(Location* targetLoc, bool locked, std::string keyID);
	bool isLocked(int index); //Checks if a specific connection is locked, used to check if the player can move to a location before moving there
	bool unlockDoor(int index, Inventory& playerInventory); //Checks the player's inventory for the correct key and unlocks the location if found
	void unlockNextDoor(Location* target);
	void setLocked(int index, bool locked);
	void outputDoors();
	void enterLocation();

	

	//Event logic

	virtual bool canStartEvent();
	virtual std::string getEventPrompt();
	virtual void startEvent();
};