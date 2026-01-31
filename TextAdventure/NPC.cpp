#include "NPC.h"
#include <iostream>

NPC::NPC()
{
	this->health = 0;
	this->name = "Unknown";
	this->alive = false;
}

NPC::NPC(string nName)
{
	this->health = 100;
	this->name = nName;
	this->alive = false;
}

string NPC::getName()
{
	return this->name;
}

int NPC::getHealth()
{
	return this->health;
}

void NPC::damage(int toDamage)
{
	this->health -= toDamage;
}

bool NPC::isAlive()
{
	return this->alive;
}

void NPC::kill()
{
	this->alive = false;
	this->health = 0;
	cout << this->name << " has been killed." << endl;
}
