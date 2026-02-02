#pragma once
#include <iostream>
using namespace std;

class BasicEnemy
{
protected:
	string name;
	int health;
	bool alive;

public:
	BasicEnemy();
	BasicEnemy(string nName);

	string getName();
	int getHealth();
	void damage(int toDamage);
	void heal(int healBy);

	bool isAlive();
	void kill();

	//virtual void update(Player& currPlayer) = 0;
};

