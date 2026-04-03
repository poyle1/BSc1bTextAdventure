#pragma once
#include <iostream>
#include "Location.h"

namespace MilkAndSugar::UI
{
	class Text
	{
	private:
	public:
		void printArt(std::string artName);
		void printDialogue(std::string artName, std::string dialogue);
		void gameIntro();
		void lineBreak();
	};
};