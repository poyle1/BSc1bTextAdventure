#pragma once
#include <iostream>
#include "Location.h"

//Class used to output random text depending on the situation, such as different messages when the player tries to open a locked door
class Text
{
private:
	
	
public:

	void ascii1();
	void gameIntro();
	void titleScreen();
	void asciiArt(Location& currentLocation);
};
