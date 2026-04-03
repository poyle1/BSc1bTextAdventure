#pragma once
#include <vector>
#include <string>
#include "Item.h"
#include "Inventory.h"
#include "Quest.h"
#include "RecipeBuilder.h"

namespace MilkAndSugar::World
{
	class Location
	{
	protected:
		//attributes
		struct Door
		{
			Location* destination = nullptr;
			bool locked = false;
			std::string requiredKeyID = "";
		};
		int m_index; //Used to compare locations to doors and keys
		std::string m_name;
		std::string m_inspectText;
		MilkAndSugar::World::Inventory m_locItems;
		std::vector<Door> m_doors; //Each location has a list of doors, 
		
	public:
		//Constructors//
		Location();
		Location(const int nIndex, std::string nName);

		//Getters and setters/
		std::string getName() const;
		std::string getInspectText() const;
		void setInspectText(std::string nText);
		int getIndex() const; //gets the index number of the selected location

		//Items
		MilkAndSugar::World::Inventory& getInventory();
		bool hasItems();
		void itemCheck();
		void outputItems();
		void investigateRoom(MilkAndSugar::World::Inventory& playerInventory);

		//Door/Connection Logic
		void addDoor(Location* targetLoc, bool locked, std::string keyID);
		int getNumDoors();
		Location* getDoor(int index);
		bool isDoorLocked(int index); //Checks if a specific connection is locked, used to check if the player can move to a location before moving there
		bool unlockDoor(int index, MilkAndSugar::World::Inventory& playerInventory); //Checks the player's inventory for the correct key and unlocks the location if found
		void unlockNextDoor(Location* target);
		void setLocked(int index, bool locked);
		void outputDoors();
		void enterLocation();

		//Event logic
		virtual bool canStartEvent(MilkAndSugar::World::Inventory& playerInventory, int reqAmount);
		virtual std::string getEventPrompt();
		virtual void startEvent(MilkAndSugar::Core::RecipeBuilder nRecipe, MilkAndSugar::Object::Player& nPlayer, MilkAndSugar::Core::Quest nQuest);

	};
}