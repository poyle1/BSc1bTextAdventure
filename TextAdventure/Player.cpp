//#include "Player.h"
//
//Player::Player()
//{
//	this->health = 100;
//	this->alive = true;
//}
//
//Player::Player(std::string nName)
//{
//	this->health = 100;
//	this->alive = true;
//	this->name = nName;
//}
//
//int Player::getHealth()
//{
//	return this->health;
//}
//
//void Player::damage(int toDamage)
//{
//	this->health -= toDamage;
//	if (this->health <= 0) {
//		this->alive = false;
//	}
//}
//
//void Player::heal(int toHeal)
//{
//	this->health += toHeal;
//}
//
//void Player::setName(std::string nName)
//{
//	this->name = nName;
//}
//
//std::string Player::getName()
//{
//	return this->name;
//}
//
//bool Player::isAlive()
//{
//	return this->alive;
//}
//
//void Player::kill()
//{
//	this->alive = false;
//}
