#pragma once
#include "Text.h"
#include <iostream>
#include "Location.h"
#include <vector>

namespace GameObject
{
	class Game
	{
	private:
		std::vector<Location*> m_worldMap;
		bool m_isRunning = true;
		Location* m_currentLocation;

	public:
		Game();
		Game(bool nRunning, Location* nStartLocation = nullptr);

		//void run();
		void mainMenu();
		void displayRules();
		void displayCredits();

		void loadLocations(std::string filename);
		void loadDoors(std::string filename);
		void loadItems(std::string filename);
		void loadWorld(std::string locFileName, std::string doorFileName, std::string itemFileName);

		Location* getCurrentLocation();
		void setCurrentLocation(Location* newLoc);
		void movePlayer(int nextLocationIndex);

		//debug functions
		void outputWorld();
	};
}