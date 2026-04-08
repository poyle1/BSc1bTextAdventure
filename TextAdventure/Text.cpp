#include "Text.h"
#include "Utility.h"
#include "Player.h"
#include <iostream> //cout
#include <fstream> // ifstream and ofstream
#include <string> // getline
#include "Common.h"

namespace MilkAndSugar::UI
{
	void Text::loadArtLibrary(std::string fileName)
	{
		std::ifstream artFile(fileName);
		if (!artFile.is_open())
		{
			std::cout << "Error, could not find file " << fileName << std::endl;
			return;
		}

		std::string artLine;
		std::string searchTag = "";
		std::string artBlock = "";

		while (getline(artFile, artLine))
		{
			//Detect Tag
			if (!artLine.empty() && artLine.front() == '[' && artLine.back() == ']')
			{
				//If a tag is in progress, add it to the library before moving on to the next tag
				if (!searchTag.empty()) //safety check
				{
					//makes a new entry
					m_artLibrary[searchTag] = artBlock;
				}
				
				//Start new tag
				searchTag = artLine.substr(1, artLine.size() - 2);
				//artLine.erase(0, 1);
				//artLine.erase(artLine.size() - 1);
				artBlock = "";
			
			}
			else if (!searchTag.empty())
			{
				artBlock += artLine + "\n";
			}
		}

		if (!searchTag.empty())
		{
			m_artLibrary[searchTag] = artBlock;
		}
		artFile.close();
	}

	void Text::printArt(std::string artName)
	{
		if (m_artLibrary.count(artName))
		{
			std::cout << m_artLibrary[artName];
		}
		else
		{
			std::cout << "Error: Art " << artName << " not found in library." << std::endl;
		}
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
		dialogueBox("John", "JOHN");
		std::cout << "John: Oh hello " << nPlayer.getName() << "!" << std::endl;
		std::cout << "John: I'm glad you're here - I was getting a bit bored on my own." << std::endl;
		std::cout << "John: I was just about to make myself a tea, but I've unpacked the shopping in a VERY strange way..." << std::endl;
		std::cout << "John: Please could you have a look around and make me a tea once you have everything?" << std::endl;
	}
	void Text::johnDialogue2(const Object::Player& nPlayer)
	{
		dialogueBox("John", "JOHN");
		std::cout << "\"How's that tea coming along, " << nPlayer.getName() << "?\"" << std::endl;
		std::cout << "\"The house is a bit of a mess, but you should be able to find what you need if you look around.\"" << std::endl;
		std::cout << "\"There is a key somewhere in here for my bedroom. I think I left the sugar in there...\"" << std::endl;
	}
	void Text::johnDialogue3(const Object::Player& nPlayer)
	{
		dialogueBox("John", "JOHN");
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