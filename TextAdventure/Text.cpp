#include "Text.h"
#include "Utility.h"
#include "Player.h"
#include <iostream> //cout
#include <fstream> // ifstream and ofstream
#include <string> // getline
#include "Common.h"

namespace MilkAndSugar::UI
{
	void Text::loadArtLibrary(std::string filename)
	{
		std::ifstream locationFile(filename);
		if (!locationFile.is_open())
		{
			std::cout << "Error, could not find file " << filename << std::endl;
			return;
		}

		std::string artLine;
		bool found = false;

		std::string searchTag = "[" + artName + "]";

		while (getline(artFile, artLine))
		{
			if (artLine == searchTag)
			{
				found = true;
				continue; //Skips the line where the searchTag is found
			}
			if (found)
			{
				if (artLine.size() > 0 && artLine[0] == '[')
				{
					break; //Stops printing if the next search tag is hit
				}
				std::cout << artLine << std::endl;
			}
		}
		if (!found)
		{
			std::cout << "Art[" << artName << "] not found." << std::endl;
		}
		artFile.close();
	}

	//void Game::loadLocations(std::string filename)
	//{
	//	std::ifstream locationFile(filename);

	//	if (!locationFile.is_open())
	//	{
	//		std::cout << "Error, could not find file " << filename << std::endl;
	//		return;
	//	}

	//	std::string row;
	//	std::stringstream rowstream;

	//	getline(locationFile, row); // skips header of csv

	//	while (getline(locationFile, row))
	//	{
	//		rowstream = std::stringstream(row); //Convert each row to a stringstream
	//		std::string index, name, isEventRoom, EventPrompt, ReqQItems, EventType;

	//		getline(rowstream, index, ',');
	//		getline(rowstream, name, ',');
	//		getline(rowstream, isEventRoom, ',');

	//		bool eventRoom = (isEventRoom == "true");

	//		if (eventRoom)
	//		{
	//			getline(rowstream, EventPrompt, ',');
	//			getline(rowstream, ReqQItems, ',');
	//			getline(rowstream, EventType, ',');
	//			World::EventRoom* newEvent = new World::EventRoom(stoi(index), name, EventPrompt, stoi(ReqQItems), EventType);
	//			m_worldMap.push_back(newEvent);
	//		}
	//		else
	//		{
	//			World::Location* newLocation = new World::Location(stoi(index), name);
	//			m_worldMap.push_back(newLocation);
	//		}
	//	}
	//	locationFile.close();
	//	if (!m_worldMap.empty())
	//	{
	//		m_currentLocation = m_worldMap.front();
	//	}
	//}

	void Text::printArt(std::string artName)
	{
		std::ifstream artFile("./Data/asciiAssets.txt");
		std::string artLine;
		bool found = false;

		std::string searchTag = "[" + artName + "]";

		while (getline(artFile, artLine))
		{
			if (artLine == searchTag)
			{
				found = true;
				continue; //Skips the line where the searchTag is found
			}
			if (found)
			{
				if (artLine.size() > 0 && artLine[0] == '[')
				{
					break; //Stops printing if the next search tag is hit
				}
				std::cout << artLine << std::endl;
			}
		}
		if (!found)
		{
			std::cout << "Art[" << artName << "] not found." << std::endl;
		}
		artFile.close();
	}

	void Text::printDialogue(std::string artName, std::string dialogue)
	{
		system("cls");
		printArt(artName); //Draw ASCII art
		std::cout << dialogue << std::endl << std::endl; //Print dialogue
		system("pause");
	}

	void Text::gameIntro()
	{
		printDialogue("INTRO", "Hello!");
		printDialogue("INTRO", "Thank you for popping round.");
		printDialogue("INTRO", "I get very lonely sometimes...");
		printDialogue("INTRO", "...");
		printDialogue("INTRO", "Would you like me to tell you a story?");
		printDialogue("INTRO", "Its about history!");
		printDialogue("INTRO", "Lost history...");
		printDialogue("INTRO", "But first, can you make me a cup of tea?");
	}

	void Text::dialogueBox(std::string nCharacter, std::string nArtName)
	{
		system("cls");
		lineBreak();
		std::cout << nCharacter << std::endl;
		lineBreak();
		printArt(nArtName);
		lineBreak();
		lineSpace();
	}

	void Text::johnDialogue1(const MilkAndSugar::Object::Player& nPlayer)
	{
		system("cls");
		lineBreak();
		std::cout << "John" << std::endl;
		lineBreak();
		printArt("JOHN");
		lineBreak();
		lineSpace();
	}
	void Text::johnDialogue2(const Object::Player& nPlayer)
	{
		system("cls");
		lineBreak();
		std::cout << "John" << std::endl;
		lineBreak();
		printArt("JOHN");
		lineBreak();
		lineSpace();
		std::cout << "\"How's that tea coming along, " << nPlayer.getName() << "?\"" << std::endl;
		std::cout << "\"The house is a bit of a mess, but you should be able to find what you need if you look around.\"" << std::endl;
		std::cout << "\"There is a key somewhere in here for my bedroom. I think I left the sugar in there...\"" << std::endl;
	}
	void Text::johnDialogue5(const Object::Player& nPlayer)
	{
		std::cout << "John: Oh thank you" << nPlayer.getName() << "! This is just what I needed." << std::endl;
		std::cout << "John: *sips*" << std::endl;
		std::cout << "John: *...*" << std::endl;
		std::cout << "John: *blows*" << std::endl;
		std::cout << "John: *sips*" << std::endl;
		std::cout << "John: *slurps*" << std::endl;
		std::cout << "John: Now then, let me tell you all about a tale of lost histories!" << std::endl;
	}
	void Text::lineBreak()
	{
		std::cout << "====================================================================================================\n";
	}
	void Text::lineSpace()
	{
		std::cout << std::endl;
	}
}