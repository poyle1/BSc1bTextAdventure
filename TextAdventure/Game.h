#pragma once
#include <vector>
#include "Location.h"

class Game
{
private:
	Location* pCurrentLocation;

	Location livingRoom;
	Location hallWay;
	Location bedroom;
	Location kitchen;
	Location bathroom1;
	Location bathroom2;
	Location frontGarden;
	Location backGarden;
	Location shed;
	Location garage;

public:
	//Constructor that initializes the game world and sets the starting location
    Game();
	// Getter for the current location, used to access the current location from the main game loop in TextAdventure.cpp
    Location* getCurrentLocation();
};