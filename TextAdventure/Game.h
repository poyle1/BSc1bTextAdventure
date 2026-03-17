#pragma once
#include "Text.h"
#include <iostream>
#include "Location.h"
#include <vector>

class Game
{
private:
	std::vector<Location> m_worldMap;
	Text m_ui;
	bool m_isRunning = true;
	Location* m_currentLocation;

public:
	Game();
	Game(bool nRunning, Location* nStartLocation = nullptr);

	void run();
	void mainMenu();
	void displayRules();

	void loadWorld(string filename);
	void outputWorld();

	Location* getCurrentLocation();
	void setCurrentLocation(Location* newLoc);
};