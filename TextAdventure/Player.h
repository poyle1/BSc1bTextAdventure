#pragma once
#include <iostream>
#include "Inventory.h"

namespace MilkAndSugar::Object
{
	class Player
	{
	private:
		std::string m_name;
		MilkAndSugar::World::Inventory m_playerInv;
		bool m_hasActiveQuest;

	public:
		Player();
		Player(std::string nName);

		void setName(std::string nName);
		std::string getName() const;

		MilkAndSugar::World::Inventory& getInventory();

		bool getHasActiveQuest() const;
		void setHasActiveQuest(bool hasActive);
	};
}