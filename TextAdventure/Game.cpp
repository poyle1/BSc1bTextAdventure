#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Utility.h"

using namespace std;
using namespace Utility;

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
		cout << "====================================================================================================\n";
		m_ui.printArt("TITLESCREEN");
		cout << "====================================================================================================\n";
		cout << "Enter '1' to start a new game.\n";
		cout << "Enter '2' to display the rules.\n";
		cout << "Enter '3' to quit the game.\n";
		cout << "====================================================================================================\n";
		cout << "Enter: ";

		//User Input//
		int userInput = getValidIntInput(1, 3);
		cout << endl;

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
			cout << "Exiting game - Goodbye for now!" << endl;
			pauseAndFlush();
			exit(0);
		}
	}
}

void Game::displayRules()
{
	system("cls");
	m_ui.printDialogue("RULES", "1) Collect ingredients. 2) Make the tea!");
}

void Game::loadLocations(string filename)
{
	ifstream locationFile(filename);

	if (!locationFile.is_open())
	{
		cout << "Error, could not find file " << filename << endl;
		return;
	}

	string row;
	stringstream rowstream;

	getline(locationFile, row); // skips header of csv

	while (getline(locationFile, row))
	{
		rowstream = stringstream(row); //Convert each row to a stringstream
		string index, name;

		getline(rowstream, index, ',');
		getline(rowstream, name, ',');

		

		Location tempLocation = Location(stoi(index), name);
		m_worldMap.push_back(tempLocation);
	}
	locationFile.close();
	if (!m_worldMap.empty())
	{
		m_currentLocation = &m_worldMap.front();
	}
}

void Game::loadDoors(string filename)
{
	ifstream locationFile(filename);

	if (!locationFile.is_open())
	{
		cout << "Error, could not find file " << filename << endl;
		return;
	}

	string row;
	stringstream rowstream;

	getline(locationFile, row); // skips header of csv

	while (getline(locationFile, row))
	{
		rowstream = stringstream(row); //Convert each row to a stringstream
		string indexOrigin, indexDestination, isLocked, doorID, destinationName;

		getline(rowstream, indexOrigin, ',');
		getline(rowstream, indexDestination, ',');
		getline(rowstream, isLocked, ',');
		getline(rowstream, doorID, ',');
		//getline(rowstream, destinationName, ',');

		//int origin = stoi(indexOrigin);
		Location* origin = &m_worldMap[stoi(indexOrigin)];
		Location* dest = &m_worldMap[stoi(indexDestination)];
		bool locked = (isLocked == "true"); //String to bool

		origin->addDoor(dest, locked, doorID);
	}
	locationFile.close();
}

void Game::loadItems(string filename)
{
	ifstream locationFile(filename);

	if (!locationFile.is_open())
	{
		cout << "Error, could not find file " << filename << endl;
		return;
	}

	string row;
	stringstream rowstream;

	getline(locationFile, row); // skips header of csv

	while (getline(locationFile, row))
	{
		rowstream = stringstream(row); //Convert each row to a stringstream
		string indexOrigin, indexDestination, isLocked, doorID, destinationName;

		getline(rowstream, indexOrigin, ',');
		getline(rowstream, indexDestination, ',');
		getline(rowstream, isLocked, ',');
		getline(rowstream, doorID, ',');
		//getline(rowstream, destinationName, ',');

		//int origin = stoi(indexOrigin);
		Location* origin = &m_worldMap[stoi(indexOrigin)];
		Location* dest = &m_worldMap[stoi(indexDestination)];
		bool locked = (isLocked == "true"); //String to bool

		origin->addDoor(dest, locked, doorID);
	}
	locationFile.close();
}

//void Game::loadWorld(string locFileName, string doorFileName, string itemFileName)
//{
//
//}


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
		cout << "Error: Destination " << nextLocationIndex << " doesn not exist." << endl;
		system("pause");
	}
}

//debug functions
void Game::outputWorld()
{
	for (Location& l : m_worldMap)
	{
		cout << l.getIndex() << l.getName() << endl;
	}
}