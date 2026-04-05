#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Utility.h"
#include "Key.h"
#include "Common.h"
#include "EventRoom.h"

namespace MilkAndSugar::Core
{
	//Constructors
	Game::Game()
	{
		m_isRunning = true;
		m_currentLocation = nullptr;
	}

	Game::Game(bool nRunning, World::Location* nStartLocation)
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
			m_ui.printArt("TITLESCREEN");
			std::cout << "====================================================================================================\n";
			std::cout << "Enter '1' to start a new game.\n";
			std::cout << "Enter '2' for the game rules.\n";
			std::cout << "Enter '3' to open the game credits.\n";
			std::cout << "Enter '4' to quit the game.\n";
			std::cout << "====================================================================================================\n";
			std::cout << "Enter: ";

			//User Input//
			int userInput = MilkAndSugar::UI::getValidIntInput(1, 3);
			std::cout << std::endl;

			if (userInput == 1)
			{
				m_ui.gameIntro();
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
				MilkAndSugar::UI::pauseAndFlush();
				exit(0);
			}
		}
	}

	void Game::displayRules()
	{
		system("cls");
		m_ui.printDialogue("RULES", "1) Collect ingredients. 2) Make the tea!");
	}

	void Game::displayCredits()
	{
		system("cls");
		std::cout << "====================================================================================================\n";
		m_ui.printArt("CREDITS");
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
		std::cout << "Misc art and titles created by the ASCII Art Archive ASCII Art Tools." << std::endl;
		//std::cout << " " << std::endl;
		std::cout << std::endl;
		std::cout << "====================================================================================================\n";
		system("pause");
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
			std::string index, name, isEventRoom, EventPrompt, ReqQItems;

			getline(rowstream, index, ',');
			getline(rowstream, name, ',');
			getline(rowstream, isEventRoom, ',');

			bool eventRoom = (isEventRoom == "true");

			if (eventRoom)
			{
				getline(rowstream, EventPrompt, ',');
				getline(rowstream, ReqQItems, ',');
				World::EventRoom* newEvent = new World::EventRoom(stoi(index), name, EventPrompt, stoi(ReqQItems));
				m_worldMap.push_back(newEvent);
			} 
			else
			{
				World::Location* newLocation = new World::Location(stoi(index), name);
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

			World::Location* origin = m_worldMap[stoi(indexOrigin)];
			World::Location* dest = m_worldMap[stoi(indexDestination)];
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
				Object::Key* newKey = new Object::Key(name, description, key, keyID);
				World::Location* pAddTo = m_worldMap[stoi(addTo)];
				pAddTo->getInventory().addItem(newKey);
			}
			else
			{
				Object::Item* newItem = new Object::Item(name, description, questItem);
				World::Location* pAddTo = m_worldMap[stoi(addTo)];
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


	World::Location* Game::getCurrentLocation()
	{
		return m_currentLocation;
	}

	void Game::setCurrentLocation(World::Location* newLoc)
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

	//debug functions
	void Game::outputWorld()
	{
		for (World::Location* l : m_worldMap)
		{
			std::cout << l->getIndex() << l->getName() << std::endl;
		}
	}
}