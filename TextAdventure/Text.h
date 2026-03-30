#pragma once
#include <iostream>
#include "Location.h"

//Class used to output random text depending on the situation, such as different messages when the player tries to open a locked door
class Text
{
private:
	
	
public:
	void printArt(std::string artName);
	void printDialogue(std::string artName, std::string dialogue);
	void gameIntro();
};
