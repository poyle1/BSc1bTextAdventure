#include "Location.h"
#include "Utility.h"
#include "Inventory.h"
#include <iostream>
#include <vector>
#include "common.h"

namespace MilkAndSugar::World
{
	//Constructors//
	Location::Location()
	{
		m_index = NULL;
		m_name = "A location";
	}

	Location::Location(const int nIndex, std::string nName)
	{
		m_index = nIndex;
		m_name = nName;
	}

	//Getters and setters//
	std::string Location::getName() const
	{
		return m_name;
	}

	std::string Location::getInspectText() const
	{
		return m_inspectText;
	}

	void Location::setInspectText(std::string nText)
	{
		m_inspectText = nText;
	}

	int Location::getIndex() const
	{
		return m_index;
	}

	//Items//
	World::Inventory& Location::getInventory()
	{
		return m_locItems;
	}

	bool Location::hasItems()
	{
		if (m_locItems.isEmpty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Location::itemCheck()
	{
		if (hasItems())
		{
			std::cout << "There are no items in this room." << std::endl;
		}
		else
		{
			std::cout << "There may be items in this room." << std::endl;
		}
	}

	void Location::outputItems()
	{
		for (int i = 0; i < m_locItems.getSize(); i++)
		{
			std::cout << i + 1 << ")" << m_locItems.getItem(i);
		}
	}

	void Location::investigateRoom(World::Inventory& playerInventory)
	{
		//std::cout << getInspectText() << std::endl;
		if (hasItems())
		{
			std::cout << "There doesn't seem to be anything useful in here." << std::endl;
			return;
		}
		std::cout << "You look around and grab: " << std::endl;
		for (Object::Item* collectedItem : m_locItems.getItems())
		{
			if (collectedItem == nullptr) //Safety check
			{
				std::cout << "error" << std::endl;
			}
			std::cout << "- " << collectedItem->getName() << std::endl;
			playerInventory.addItem(collectedItem);
		}
		getInventory().clear();
	}

	//Door/connection Logic//
	void Location::addDoor(Location* nDestination, bool nLocked, std::string nKeyID)
	{
		Door newDoor;
		newDoor.destination = nDestination;
		newDoor.locked = nLocked;
		newDoor.requiredKeyID = nKeyID;
		m_doors.push_back(newDoor);
	}

	int Location::getNumDoors()
	{
		return m_doors.size();
	}

	Location* Location::getDoor(int index)
	{
		if (index < 0 || index >= m_doors.size())
		{
			return nullptr; //Invalid Index Check
		}
		return m_doors[index].destination;
	}

	bool Location::isDoorLocked(int index)
	{
		if (index < 0 || index >= m_doors.size())
		{
			return false; //Invalid Index Check
		}
		return m_doors[index].locked;
	}

	bool Location::unlockDoor(int index, World::Inventory& playerInventory)
	{
		if (index < 0 || index >= m_doors.size())
		{
			return false; //Invalid Index Check
		}
		Door& currentDoor = m_doors[index];

		for (int i = 0; i < playerInventory.getItems().size(); i++)
		{
			if (playerInventory.getItem(i)->getKeyID() == m_doors[index].requiredKeyID)
			{
				currentDoor.locked = false;
				Location* nextRoom = currentDoor.destination;
				nextRoom->unlockNextDoor(this);

				std::cout << "You use the " << playerInventory.getItem(i)->getName() << " to unlock the door." << std::endl;
				playerInventory.getItems().erase(playerInventory.getItems().begin() + i);
				return true; //Exit loop
			}
		}
		return false; //No matching key found in inventory
	}

	void Location::unlockNextDoor(Location* target)
	{
		for (auto& door : m_doors)
		{
			if (door.destination == target)
			{
				door.locked = false;
			}
		}
	}

	void Location::setLocked(int index, bool nLocked)
	{
		m_doors[index].locked = nLocked;
	}

	void Location::outputDoors()
	{
		for (int i = 0; i < m_doors.size(); i++)
		{
			std::cout << i + 1 << ") Enter the: " << m_doors[i].destination->getName();
			if (m_doors[i].locked)
			{
				std::cout << " [LOCKED]";
			}
			std::cout << std::endl;
		}
	}

	void Location::enterLocation()
	{
		std::cout << "You have entered the " << getName() << "." << std::endl;
		UI::pauseAndFlush();
	}

	//Event logic//
	bool Location::canStartEvent(World::Inventory& playerInventory, int reqAmount)
	{
		return false;
	}

	std::string Location::getEventPrompt()
	{
		return std::string("");
	}

	void Location::startEvent(Core::RecipeBuilder nRecipe, Object::Player& nPlayer, Core::Quest nQuest)
	{
		return;
	}
}