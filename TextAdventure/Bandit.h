#pragma once
#include <iostream>
#include "Monster.h"


enum banditState {
	SHOOTING,
	AIMING,
	WAITING
};

class Bandit : public Monster
{
private:
	banditState state;

public:
	Bandit();
	Bandit(string nName);

	void update(Player& currPlayer) override;
};

