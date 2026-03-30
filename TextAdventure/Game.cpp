#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Utility.h"
#include "Key.h"


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
		m_ui.printArt("TITLESCREEN");
		std::cout << "====================================================================================================\n";
		std::cout << "Enter '1' to start a new game.\n";
		std::cout << "Enter '2' to display the rules.\n";
		std::cout << "Enter '3' to quit the game.\n";
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
		std::string index, name, isEventRoom;

		getline(rowstream, index, ',');
		getline(rowstream, name, ',');
		getline(rowstream, isEventRoom, ',');

		bool eventRoom = (isEventRoom == "true");

		if (eventRoom)
		{

		}

		Location tempLocation = Location(stoi(index), name);
		m_worldMap.push_back(tempLocation);
		
	}
	locationFile.close();
	if (!m_worldMap.empty())
	{
		m_currentLocation = &m_worldMap.front();
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
	
		Location* origin = &m_worldMap[stoi(indexOrigin)];
		Location* dest = &m_worldMap[stoi(indexDestination)];
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
			Location* pAddTo = &m_worldMap[stoi(addTo)];
			pAddTo->getInventory().addItem(newKey);
		}
		else 
		{
			Item* newItem = new Item(name, description, questItem);
			Location* pAddTo = &m_worldMap[stoi(addTo)];
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
	if (nextLocationIndex >= 0 && nextLocationIndex < m_worldMap.size())
	{
		m_currentLocation = &m_worldMap[nextLocationIndex]; //Sets the current location to the mem address of
		//the selected location (stored in the worldmap vec)
		m_currentLocation->enterLocation();
	}
	else
	{
		std::cout << "Error: Destination " << nextLocationIndex << " doesn not exist." << std::endl;
		system("pause");
	}
}

//debug functions
void Game::outputWorld()
{
	for (Location& l : m_worldMap)
	{
		std::cout << l.getIndex() << l.getName() << std::endl;
	}
}