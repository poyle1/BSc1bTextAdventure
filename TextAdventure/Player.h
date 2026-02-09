#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
	int health;
	bool alive;
	string name;
	//Inventory inventory; //Player's inventory, can hold items the player has collected

public:
	Player();
	Player(string nName);

	int getHealth();
	void damage(int toDamage);
	void heal(int toHeal);

	void setName(string nName);
	string getName();

	bool isAlive();
	void kill();
};
