#pragma once
#include <iostream>

using namespace std;


class Monster
{
private:
	string name;
	string description;
	string type;
	int health;
	int attackPwr;

public:
	Monster();
	Monster(string nName, string nDesc, string nType, int nHealth, int nAttackPwr);


	string getName();
	string getDescription();
	string getType();
	int getHealth();
	int getAttackPwr();
};

