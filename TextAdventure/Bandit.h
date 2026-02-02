#pragma once
#include <iostream>
#include "BasicEnemy.h"
#include "Player.h"


enum banditState {
	SHOOTING,
	AIMING,
	WAITING
};

class Bandit : public BasicEnemy
{
private:
	banditState state;

public:
	Bandit();
	Bandit(string nName);

	void update(Player& currPlayer);
};

