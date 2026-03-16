#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Utility.h"

using namespace std;
using namespace Utility;

void Game::mainMenu() 
{
	while (isRunning) 
	{
		system("cls");
		cout << "====================================================================================================\n";
		ui.printArt("TITLESCREEN");
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
			ui.gameIntro();
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
	ui.printDialogue("RULES", "1) Collect ingredients. 2) Make the tea!");
}

void Game::loadWorld(string filename)
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
		string name;

		getline(rowstream, name, ',');
		//getline(rowstream, description, ',');

		Location tempLocation = Location(name);
		worldMap.push_back(tempLocation);
	}
	locationFile.close();
}

void Game::outputWorld()
{
	for (Location l : worldMap)
	{
		cout << l.getName() << endl;
	}
}

void Game::setStartLoc()
{
	newLoc = this->worldMap[0];
}