#pragma once
#include <iostream>

class BasicEnemy
{
protected:
	std::string name;
	int health;
	bool alive;

public:
	BasicEnemy();
	BasicEnemy(std::string nName);

	std::string getName();
	int getHealth();
	void damage(int toDamage);
	void heal(int healBy);

	bool isAlive();
	void kill();

	//virtual void update(Player& currPlayer) = 0;
};

