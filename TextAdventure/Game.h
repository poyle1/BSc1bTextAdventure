#pragma once
#include "Text.h"
#include <iostream>
#include "Location.h"
#include <vector>

class Game
{
private:
	vector<Location> worldMap;
	Text ui;
	bool isRunning = true;

public:
	void run();
	void mainMenu();
	void displayRules();

	void loadWorld(string filename);
	void outputWorld();

	void setStartLoc();
	Location* getLocation(int index);
};