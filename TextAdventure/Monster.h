#pragma once
#include <iostream>
using namespace std;

class Monster
{
protected:
	int health;
	string name;
	bool alive;

public:
	Monster();
	Monster(string nName);

	string getName();
	int getHealth();
	void damage(int toDamage);

	bool isAlive();
	void kill();

	virtual void update(Player& currPlayer) = 0;
};

