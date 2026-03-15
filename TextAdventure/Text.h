#pragma once
#include <iostream>
#include "Location.h"

//Class used to output random text depending on the situation, such as different messages when the player tries to open a locked door
class Text
{
private:
	
	
public:
	void printArt(string artName);
	void printDialogue(string artName, string dialogue);
	void gameIntro();
};
