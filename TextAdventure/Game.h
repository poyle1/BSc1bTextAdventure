#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Location.h"

namespace GameObject
{
	class Quest;
	class Player;

	class Game
	{
	private:
		std::vector<Location*> m_worldMap;
		std::vector<Item*> m_allGameItems;
		bool m_isRunning = true;
		Location* m_currentLocation;

	public:
		Game();
		Game(bool nRunning, Location* nStartLocation = nullptr);

		//void run();
		void mainMenu(Player& nPlayer);
		void displayRules() const;
		void displayCredits() const;
		void gameOver(Quest& nQuest) const;
		void gameStart(Player& nPlayer);

		bool getIsRunning() const;
		void setIsRunning(bool nRunning);

		void loadLocations(std::string filename);
		void loadEvents(std::string filename);
		void loadDoors(std::string filename);
		void loadItems(std::string filename);
		void loadEventsMk2();
		void loadWorld(std::string locFileName, std::string doorFileName, std::string itemFileName, std::string eventFileName);

		Location* getCurrentLocation();
		void setCurrentLocation(Location* newLoc);
		void movePlayer(int nextLocationIndex);

		void currentLocationInfo() const;
		void currentActionsInfo(int investigateRoomOption, int startEventOption);

		//debug functions
		void outputWorld();
		void resetWorld();
	};
}