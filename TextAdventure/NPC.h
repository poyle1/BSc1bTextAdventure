#pragma once
#include <string>
#include "Player.h"
using namespace std;

class NPC
{
protected:
	int health;
	string name;
	bool alive;

public:
	NPC();
	NPC(string nName);

	string getName();
	int getHealth();
	void damage(int toDamage);

	bool isAlive();
	void kill();

	virtual void update(Player& currPlayer) = 0;
};