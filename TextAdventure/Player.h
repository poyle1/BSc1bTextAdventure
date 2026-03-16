#pragma once
#include <iostream>


class Player
{
private:
	int health;
	bool alive;
	std::string name;
	//Inventory inventory; //Player's inventory, can hold items the player has collected

public:
	Player();
	Player(std::string nName);

	int getHealth();
	void damage(int toDamage);
	void heal(int toHeal);

	void setName(std::string nName);
	std::string getName();

	bool isAlive();
	void kill();
};
