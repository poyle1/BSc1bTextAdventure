#pragma once
#include <string>
#include "Location.h"

namespace MilkAndSugar::Object 
{
	class Player;
}

namespace MilkAndSugar::UI
{
	class Text
	{
	private:
	public:
		void printArt(std::string artName);
		void printDialogue(std::string artName, std::string dialogue);
		void gameIntro();
		void johnDialogue1(const MilkAndSugar::Object::Player& nPlayer);
		void johnDialogue2(const MilkAndSugar::Object::Player& nPlayer);
		void lineBreak();
		void lineSpace();
	};
};