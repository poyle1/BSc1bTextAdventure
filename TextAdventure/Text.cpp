#include "Text.h"
#include "Utility.h"
#include <iostream> //cout
#include <fstream> // ifstream and ofstream
#include <string> // getline
#include "Common.h"

namespace MilkAndSugar::UI
{
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
		printDialogue("INTRO", "\"Hello!\"");
		printDialogue("INTRO", "\"Thank you for popping round.\"");
		printDialogue("INTRO", "\"I get very lonely sometimes...\"");
		printDialogue("INTRO", "\"...\"");
		printDialogue("INTRO", "\"Would you like me to tell you a story?\"");
		printDialogue("INTRO", "\"Its about history!\"");
		printDialogue("INTRO", "\"Lost history...\"");
		printDialogue("INTRO", "\"But first, can you make me a cup of tea?\"");
	}
}