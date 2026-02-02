#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

class BasicEnemy
{
protected:
	int health;
	string name;
	bool alive;

public:
	BasicEnemy();
	BasicEnemy(string nName);

	string getName();
	int getHealth();
	void damage(int toDamage);

	bool isAlive();
	void kill();

	virtual void update(Player& currPlayer) = 0;
};

