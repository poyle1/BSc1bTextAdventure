#pragma once
#include <string>
#include <map>

namespace MilkAndSugar::Object 
{
	class Player;
}

namespace MilkAndSugar::UI
{
	class Text
	{
	private:
		std::map<std::string, std::string> m_artLibrary;
	public:
		void loadArtLibrary(std::string filename);
		void printArt(std::string artName);

		void printDialogue(std::string artName, std::string dialogue);
		void gameIntro();
		void dialogueBox(std::string nCharacter, std::string nArtName);
		void johnDialogue1(const MilkAndSugar::Object::Player& nPlayer);
		void johnDialogue2(const MilkAndSugar::Object::Player& nPlayer);
		void johnDialogue3(const MilkAndSugar::Object::Player& nPlayer);
		void lineBreak();
		void lineSpace();
	};
};