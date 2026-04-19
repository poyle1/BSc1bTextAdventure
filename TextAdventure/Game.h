#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Location.h"

namespace GameObject
{
	class Quest;

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
		void gameOver(Quest& nQuest);

		bool getIsRunning() const;
		void setIsRunning(bool nRunning);

		void loadLocations(std::string filename);
		void loadEvents(std::string filename);
		void loadDoors(std::string filename);
		void loadItems(std::string filename);
		void loadWorld(std::string locFileName, std::string doorFileName, std::string itemFileName, std::string eventFileName);

		Location* getCurrentLocation();
		void setCurrentLocation(Location* newLoc);
		void movePlayer(int nextLocationIndex);

		void currentLocationInfo();
		void currentActionsInfo(int investigateRoomOption, int startEventOption);

		//debug functions
		void outputWorld();
	};
}