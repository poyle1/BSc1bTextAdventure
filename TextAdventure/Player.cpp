#include "Player.h"

#include <string>
#include <iostream>

namespace GameObject
{
	Player::Player()
	{
		m_name = "Player";
		m_hasActiveQuest = false;
	}
	Player::Player(std::string nName)
	{
		m_name = nName;
		m_hasActiveQuest = false;
	}
	Player::~Player()
	{

	}
	void Player::setName(std::string nName)
	{
		m_name = nName;
	}
	std::string Player::getName() const
	{
		return m_name;
	}
	Inventory& Player::getInventory()
	{
		return m_playerInv;
	}
	bool Player::getHasActiveQuest() const
	{
		return m_hasActiveQuest;
	}
	void Player::setHasActiveQuest(bool hasActive)
	{
		m_hasActiveQuest = hasActive;
	}
}