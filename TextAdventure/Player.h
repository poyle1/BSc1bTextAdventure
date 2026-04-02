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

	public:
		Player();
		Player(std::string nName);

		void setName(std::string nName);
		std::string getName();

		MilkAndSugar::World::Inventory& getInventory();
	};
}