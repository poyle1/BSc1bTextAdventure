#pragma once

#include <string>
#include <iostream>

#include "Inventory.h"

namespace GameObject
{
	class Player
	{
	private:
		std::string m_name;
		Inventory m_playerInv;
		bool m_hasActiveQuest;

	public:
		Player();
		Player(std::string nName);

		void setName(std::string nName);
		std::string getName() const;

		Inventory& getInventory();

		bool getHasActiveQuest() const;
		void setHasActiveQuest(bool hasActive);
	};
}