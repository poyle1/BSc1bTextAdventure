#pragma once
#include "Text.h"
#include <iostream>
#include "Location.h"
#include <vector>

namespace MilkAndSugar::Core
{
	class Game
	{
	private:
		std::vector<MilkAndSugar::World::Location*> m_worldMap;
		bool m_isRunning = true;
		MilkAndSugar::World::Location* m_currentLocation;

	public:
		Game();
		Game(bool nRunning, MilkAndSugar::World::Location* nStartLocation = nullptr);

		void run();
		void mainMenu();
		void displayRules();
		void displayCredits();

		void loadLocations(std::string filename);
		void loadDoors(std::string filename);
		void loadItems(std::string filename);
		void loadWorld(std::string locFileName, std::string doorFileName, std::string itemFileName);

		MilkAndSugar::World::Location* getCurrentLocation();
		void setCurrentLocation(MilkAndSugar::World::Location* newLoc);
		void movePlayer(int nextLocationIndex);

		//debug functions
		void outputWorld();
	};
}