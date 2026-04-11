#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "Inventory.h"

namespace UI {
	class Text;
}

namespace GameObject
{
	class Player;
	class RecipeBuilder;
	class Quest;

	class Location
	{
	protected:
		struct Door
		{
			Location* destination = nullptr;
			bool locked = false;
			std::string requiredKeyID = "";
		};
		int m_index;
		std::string m_name;
		std::string m_inspectText;
		Inventory m_locItems;
		bool m_searched;
		std::vector<Door> m_doors;
		
	public:
		Location();
		Location(const int nIndex, std::string nName);

		std::string getName() const;
		std::string getInspectText() const;
		void setInspectText(std::string nText);
		int getIndex() const; //gets the index number of the selected location

		Inventory& getInventory();
		bool hasItems();
		void itemCheck();
		void outputItems();
		void investigateRoom(Inventory& playerInventory);
		bool getSearched() const;
		void setSearched(bool nSearched);
		void searchCheck();

		void addDoor(Location* targetLoc, bool locked, std::string keyID);
		int getNumDoors();
		Location* getDoor(int index);
		bool isDoorLocked(int index); //Checks if a specific connection is locked, used to check if the player can move to a location before moving there
		bool unlockDoor(int index, Inventory& playerInventory); //Checks the player's inventory for the correct key and unlocks the location if found
		void unlockNextDoor(Location* target);
		void setLocked(int index, bool locked);
		void outputDoors();
		void enterLocation();

		virtual bool canStartEvent(Inventory& playerInventory, int reqAmount);
		virtual std::string getEventPrompt();
		virtual void startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest);
		virtual bool getIsEventRoom() const;
		virtual void setIsEventRoom(bool nIsEventRoom);
	};
}