#include "Location.h"

#include <string>
#include <iostream>
#include <vector>

#include "Utility.h"
#include "Inventory.h"
#include "Player.h"
#include "Text.h"
#include "RecipeBuilder.h"
#include "Quest.h"

namespace GameObject
{
	Location::Location()
	{
		m_index = NULL;
		m_name = "A location";
		m_searched = false;
	}

	Location::Location(const int nIndex, std::string nName)
	{
		m_index = nIndex;
		m_name = nName;
		m_searched = false;
	}

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

	Inventory& Location::getInventory()
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

	void Location::investigateRoom(Inventory& playerInventory)
	{
		//std::cout << getInspectText() \n\n;
		std::cout << "ROOM INSPECT TEXT PLACEHOLDER \n\n";
		if (!m_searched)
		{
			if (hasItems())
			{
				std::cout << "You look around and grab: " << std::endl;
				for (Item* collectedItem : m_locItems.getItems())
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
			else
			{
				std::cout << "There isn't anything useful here." << std::endl;
				m_searched = true;
				UI::pauseAndFlush();
			}
		}
		else if (m_searched)
		{
			std::cout << "You've already grabbed everything you need." << std::endl;
			UI::pauseAndFlush();
			return;
		}
	}

	bool Location::getSearched() const
	{
		return m_searched;
	}

	void Location::setSearched(bool nSearched)
	{
		m_searched = nSearched;
	}

	void Location::searchCheck()
	{
		if (m_searched)
		{
			std::cout << "AREA SEARCHED" << std::endl;
		}
		else
		{
			std::cout << "AREA UNSEARCHED" << std::endl;
		}
	}

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

	bool Location::unlockDoor(int index, Inventory& playerInventory)
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
				UI::pauseAndFlush();
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
			std::cout << "\t" <<  i + 1 << ") Enter the: " << m_doors[i].destination->getName();
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

	bool Location::canStartEvent(Inventory& playerInventory, int reqAmount)
	{
		return false;
	}

	std::string Location::getEventPrompt()
	{
		return std::string("");
	}

	void Location::startEvent(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
	{
		return;
	}

	bool Location::getIsEventRoom() const
	{
		return false;
	}

	void Location::setIsEventRoom(bool nIsEventRoom)
	{
		return;
	}
}