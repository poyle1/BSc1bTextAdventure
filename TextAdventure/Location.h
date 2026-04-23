#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include "Inventory.h"
#include "Event.h"


namespace UI {
	class Text;
}

namespace GameObject
{
	class Player;
	class RecipeBuilder;
	class Quest;
	class Location;

	struct Door
	{
		Location* destination = nullptr;
		bool locked = false;
		std::string requiredKeyID = "";
	};

	class Location
	{
	protected:
		
		int m_index;
		std::string m_name;
		std::string m_description;
		Inventory m_locItems;
		bool m_searched;
		std::vector<Door> m_doors;
		
		std::vector<Event*> m_events;
		bool m_eventPresent;

	public:
		Location();
		Location(const int nIndex, std::string nName, std::string nDescription);
		~Location();

		std::string getName() const;
		std::string getDescription() const;
		void setDescription(std::string nText);
		int getIndex() const;

		Inventory& getInventory();
		bool hasItems() const;
		void itemCheck() const;
		void outputItems();
		void investigateRoom(Inventory& playerInventory);
		bool getSearched() const;
		void setSearched(bool nSearched);
		void searchCheck() const;

		void addDoor(Location* targetLoc, bool locked, std::string keyID);
		int getNumDoors() const;
		Location* getDoor(int index);
		bool isDoorLocked(int index) const;
		bool unlockDoor(int index, Inventory& playerInventory); //Checks the player's inventory for the correct key and unlocks the location if found
		void unlockNextDoor(Location* target);
		void setLocked(int index, bool locked);
		void outputDoors() const;
		void enterLocation() const;

		bool hasEvent() const;
		std::vector<Event*>& getEvents();
		void addEvent(Event* nEvent);
		void removeEvent(int nIndex);
		Event* getEvent(int nIndex);
		void startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest, int eventID) const;
	};
}