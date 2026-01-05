#include "Monster.h"

Monster::Monster()
{
	this->name = "Unknown Monster";
	this->description = "No description available.";
	this->type = "Unknown Type";
	this->health = 100;
	this->attackPwr = 10;

}
Monster::Monster(string nName, string nDesc, string nType, int nHealth, int nAttackPwr)
{
	this->name = nName;
	this->description = nDesc;
	this->type = nType;
	this->health = nHealth;
	this->attackPwr = nAttackPwr;
}

string Monster::getName()
{
	return this->name;
}

string Monster::getDescription()
{
	return this->description;
}

string Monster::getType()
{
	return this->type;
}

int Monster::getHealth()
{
	return this->health;
}

int Monster::getAttackPwr()
{
	return this->attackPwr;
}