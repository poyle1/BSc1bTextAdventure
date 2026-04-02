#include "Player.h"
namespace MilkAndSugar::Object
{
	Player::Player()
	{
		m_name = "Player";
	}

	Player::Player(std::string nName)
	{
		m_name = nName;
	}

	void Player::setName(std::string nName)
	{
		m_name = nName;
	}

	std::string Player::getName()
	{
		return m_name;
	}
	MilkAndSugar::World::Inventory& Player::getInventory()
	{
		return m_playerInv;
	}
}