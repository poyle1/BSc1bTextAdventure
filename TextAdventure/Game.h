#pragma once
#include "Text.h"
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
};

