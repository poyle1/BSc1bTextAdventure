#include "Game.h"

#include <fstream>
#include <string>
#include <sstream>

#include "Quest.h"
#include "Utility.h"
#include "Key.h"
#include "EventRoom.h"
#include "Text.h"

namespace GameObject
{
	//Constructors
	Game::Game()
	{
		m_isRunning = true;
		m_currentLocation = nullptr;
	}

	Game::Game(bool nRunning, Location* nStartLocation)
	{
		m_isRunning = nRunning;
		m_currentLocation = nStartLocation;
	}

	void Game::mainMenu()
	{
		while (m_isRunning)
		{
			system("cls");
			std::cout << "====================================================================================================\n";
			UI::Text::getInstance().printArt("TITLESCREEN");
			std::cout << "====================================================================================================\n";
			std::cout << "\tEnter 1) New game.\n";
			std::cout << "\tEnter 2) How to play.\n";
			std::cout << "\tEnter 3) Credits.\n";
			std::cout << "\tEnter 4) Quit game.\n";
			std::cout << "====================================================================================================\n";

			//User Input//
			int userInput = UI::getValidIntInput(1, 4);
			std::cout << std::endl;

			if (userInput == 1)
			{
				UI::Text::getInstance().gameIntro();
				break;
			}
			else if (userInput == 2)
			{
				displayRules();
			}
			else if (userInput == 3)
			{
				displayCredits();
			}
			else if (userInput == 4)
			{
				std::cout << "Exiting game - Goodbye for now!" << std::endl;
				UI::pauseAndFlush();
				exit(0);
			}
		}
	}

	void Game::displayRules()
	{
		system("cls");
		UI::Text::getInstance().printArt("RULES");
		UI::Text::getInstance().lineSpace();
		char rules[] = "Navigate the house and complete actions by entering the respective\n"
						"number. Search rooms to find items that may help you in your quest.\n\n"
						"Speak to John to begin.\n";
		printf(rules);
		UI::pauseAndFlush();
	}

	void Game::displayCredits()
	{
		system("cls");
		std::cout << "====================================================================================================\n";
		UI::Text::getInstance().printArt("CREDITS");
		std::cout << "====================================================================================================\n";
		std::cout << "A game by Tyler Poyle of TyPo Games" << std::endl;
		std::cout << "Art assets, courtesy of ASCII Art Archive, asciiart.eu:" << std::endl;
		std::cout << std::endl;
		std::cout << "Living Room: Untitled by Joan G. Stark." << std::endl;
		std::cout << "Kitchen: Sink by Joan G. Stark." << std::endl;
		std::cout << "Hallway: Drawer by Riitta Rasimus." << std::endl;
		std::cout << "Bathroom: Untitled by Praseodymium 59." << std::endl;
		std::cout << "On Suite: Untitled by Joan G. Stark." << std::endl;
		std::cout << "Garage: Ready to Paint by Joan G. Stark." << std::endl;
		std::cout << "Front garden: Flower garden by Joan G. Stark." << std::endl;
		std::cout << "Back garden: Untitled by Joan G. Stark." << std::endl;
		std::cout << "Shed: Untitled by Anonymous" << std::endl;
		std::cout << "QuestCompleteP1: Coffee mug by H P Barmario." << std::endl;
		std::cout << "Misc art and titles created using the ASCII Art Archive ASCII Art Tools." << std::endl;
		std::cout << std::endl;
		std::cout << "====================================================================================================\n";
		system("pause");
	}

	void Game::gameOver(Quest& nQuest)
	{
		std::cout << "====================================================================================================\n";

		if (nQuest.getResult() == Quest::Bad)
		{ 
			UI::Text::getInstance().printArt("BadEnd");
		}
		else if (nQuest.getResult() == Quest::Neutral)
		{
			UI::Text::getInstance().printArt("NeutralEnd");
		}
		else if (nQuest.getResult() == Quest::Good)
		{
			UI::Text::getInstance().printArt("GoodEnd");
		}
		std::cout << "====================================================================================================\n";
		std::cout << "Enter '1' to quit the game.\n";
		std::cout << "Enter '2' to return to the main menu.\n";
		std::cout << "====================================================================================================\n";
		std::cout << "Enter: ";

		//User Input//
		int userInput = UI::getValidIntInput(1, 2);
		std::cout << std::endl;

		if (userInput == 1)
		{
			std::cout << "Exiting game - Thanks for playing!" << std::endl;
			UI::pauseAndFlush();
			exit(0);
		}
		else if (userInput == 2)
		{
			return;
		}
	}

	bool Game::getIsRunning() const
	{
		return m_isRunning;
	}

	void Game::setIsRunning(bool nRunning)
	{
		m_isRunning = nRunning;
	}

	void Game::loadLocations(std::string filename)
	{
		std::ifstream locationFile(filename);

		if (!locationFile.is_open())
		{
			std::cout << "Error, could not find file " << filename << std::endl;
			return;
		}

		std::string row;
		std::stringstream rowstream;

		getline(locationFile, row); // skips header of csv

		while (getline(locationFile, row))
		{
			rowstream = std::stringstream(row); //Convert each row to a stringstream
			std::string index, name, isEventRoom, EventPrompt, ReqQItems, EventType;

			getline(rowstream, index, ',');
			getline(rowstream, name, ',');
			getline(rowstream, isEventRoom, ',');

			bool eventRoom = (isEventRoom == "true");

			if (eventRoom)
			{
				getline(rowstream, EventPrompt, ',');
				getline(rowstream, ReqQItems, ',');
				getline(rowstream, EventType, ',');
				EventRoom* newEvent = new EventRoom(stoi(index), name, EventPrompt, stoi(ReqQItems),EventType);
				m_worldMap.push_back(newEvent);
			} 
			else
			{
				Location* newLocation = new Location(stoi(index), name);
				m_worldMap.push_back(newLocation);
			}
		}
		locationFile.close();
		if (!m_worldMap.empty())
		{
			m_currentLocation = m_worldMap.front();
		}
	}

	void Game::loadDoors(std::string filename)
	{
		std::ifstream locationFile(filename);

		if (!locationFile.is_open())
		{
			std::cout << "Error, could not find file " << filename << std::endl;
			return;
		}

		std::string row;
		std::stringstream rowstream;

		getline(locationFile, row); // skips header of csv

		while (getline(locationFile, row))
		{

			rowstream = std::stringstream(row); //Convert each row to a stringstream
			std::string indexOrigin, indexDestination, isLocked, doorID;

			getline(rowstream, indexOrigin, ',');
			getline(rowstream, indexDestination, ',');
			getline(rowstream, isLocked, ',');
			getline(rowstream, doorID, ',');

			Location* origin = m_worldMap[stoi(indexOrigin)];
			Location* dest = m_worldMap[stoi(indexDestination)];
			bool locked = (isLocked == "true"); //String to bool

			origin->addDoor(dest, locked, doorID);
		}
		locationFile.close();
	}

	void Game::loadItems(std::string filename)
	{
		std::ifstream locationFile(filename);

		if (!locationFile.is_open())
		{
			std::cout << "Error, could not find file " << filename << std::endl;
			return;
		}

		std::string row;
		std::stringstream rowstream;

		getline(locationFile, row); // skips header of csv

		while (getline(locationFile, row))
		{
			rowstream = std::stringstream(row); //Convert each row to a stringstream

			std::string addTo, name, description, isQuestItem, isKey, keyID;

			getline(rowstream, addTo, ',');
			getline(rowstream, name, ',');
			getline(rowstream, description, ',');
			getline(rowstream, isQuestItem, ',');
			getline(rowstream, isKey, ',');

			bool key = (isKey == "true"); //String to bool
			bool questItem = (isQuestItem == "true"); //String to bool

			if (key)
			{
				getline(rowstream, keyID, ',');
				Key* newKey = new Key(name, description, key, keyID);
				Location* pAddTo = m_worldMap[stoi(addTo)];
				pAddTo->getInventory().addItem(newKey);
			}
			else
			{
				Item* newItem = new Item(name, description, questItem);
				Location* pAddTo = m_worldMap[stoi(addTo)];
				pAddTo->getInventory().addItem(newItem);
			}
		}
		locationFile.close();
	}

	void Game::loadWorld(std::string locFileName, std::string doorFileName, std::string itemFileName)
	{
		loadLocations(locFileName);
		loadDoors(doorFileName);
		loadItems(itemFileName);
	}


	Location* Game::getCurrentLocation()
	{
		return m_currentLocation;
	}

	void Game::setCurrentLocation(Location* newLoc)
	{
		m_currentLocation = newLoc;
	}


	void Game::movePlayer(int nextLocationIndex)
	{
		if (nextLocationIndex <= 0 || nextLocationIndex > m_worldMap.size()) //Safety check
		{
			std::cout << "Error: Destination " << nextLocationIndex << " doesn not exist." << std::endl;
			system("pause");
		}
		else
		{
			m_currentLocation = m_worldMap[nextLocationIndex];
			m_currentLocation->enterLocation();
		}
	}

	void Game::currentLocationInfo()
	{
		UI::Text::getInstance().lineBreak(); ///
		std::cout << "Current location: " << m_currentLocation->getName() << " | ";
		m_currentLocation->searchCheck();
		UI::Text::getInstance().lineBreak(); ///
		UI::Text::getInstance().printArt(m_currentLocation->getName());
		UI::Text::getInstance().lineBreak(); ///
	}

	void Game::currentActionsInfo(int investigateRoomOption, int startEventOption)
	{
		std::cout << "\tAvailable Actions:" << "\n";
		getCurrentLocation()->outputDoors();
		std::cout << "\t" << investigateRoomOption << ") Investigate the room" << std::endl;
		if (getCurrentLocation()->getIsEventRoom() == true)
		{
			std::cout << "\t" << startEventOption << ") " << getCurrentLocation()->getEventPrompt();
			UI::Text::getInstance().lineSpace();
		}
		UI::Text::getInstance().lineSpace();
		UI::Text::getInstance().lineBreak(); ///
		std::cout << "Enter a character to complete an action:\n\n";
	}

	//debug functions
	void Game::outputWorld()
	{
		for (Location* l : m_worldMap)
		{
			std::cout << l->getIndex() << l->getName() << std::endl;
		}
	}
}