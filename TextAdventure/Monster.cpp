#include "Monster.h"

AbstractEnemy::Monster()
{
	this->health = 0;
	this->name = "Unknown";
	this->alive = false;
}

Monster::Monster(string nName)
{
	this->health = 100;
	this->name = nName;
	this->alive = false;
}

string Monster::getName()
{
	return this->name;
}

int Monster::getHealth()
{
	return this->health;
}

void Monster::damage(int toDamage)
{
	this->health -= toDamage;
}

bool Monster::isAlive()
{
	return this->alive;
}

void Monster::kill()
{
	this->alive = false;
}
