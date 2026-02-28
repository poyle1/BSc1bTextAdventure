//#include "Game.h"
//#include <vector>
//#include "Location.h"
//#include <iostream>
//
//Game::Game()
//{
//	locations.push_back(Location("Living Room", false)); //0
//	locations.push_back(Location("Hallway", false)); //1
//	locations.push_back(Location("Bedroom", true)); //2
//	locations.push_back(Location("Kitchen", true)); //3
//	locations.push_back(Location("Bathroom", false)); //4
//	locations.push_back(Location("En Suite Bathroom", false)); //5
//	locations.push_back(Location("Front Garden", false)); //6
//	locations.push_back(Location("Back Garden", false)); //7
//	locations.push_back(Location("Shed", false)); //8
//	locations.push_back(Location("Garage", true)); //9
//
//	pCurrentLocation = &locations[0];
//
//	locations[0].addConnection(&locations[1]); //Living Room -> Hallway
//	locations[0].addConnection(&locations[3]); //Living Room -> Kitchen
//	locations[1].addConnection(&locations[0]); //Hallway -> Living Room
//	locations[1].addConnection(&locations[2]); //Hallway -> Bedroom
//	locations[1].addConnection(&locations[3]); //Hallway -> Kitchen
//	locations[1].addConnection(&locations[6]); //Hallway -> Front Garden
//	locations[1].addConnection(&locations[7]); //Hallway -> Back Garden
//	locations[1].addConnection(&locations[4]); //Hallway -> Bathroom
//	locations[6].addConnection(&locations[1]); //Front Garden -> Hallway
//	locations[6].addConnection(&locations[7]); //Front Garden -> Back Garden
//	locations[6].addConnection(&locations[9]); //Front Garden -> Garage
//	locations[7].addConnection(&locations[1]); //Back Garden -> Hallway
//	locations[7].addConnection(&locations[6]); //Back Garden -> Front Garden
//	locations[7].addConnection(&locations[8]); //Back Garden -> Shed
//	locations[7].addConnection(&locations[9]); //Back Garden -> Garage
//	locations[8].addConnection(&locations[7]); //Shed -> Back Garden
//	locations[2].addConnection(&locations[1]); //Bedroom -> Hallway
//	locations[2].addConnection(&locations[5]); //Bedroom -> En Suite Bathroom
//	locations[4].addConnection(&locations[1]); //Bathroom -> Hallway
//	locations[5].addConnection(&locations[2]); //En Suite Bathroom -> Bedroom
//	locations[3].addConnection(&locations[0]); //Kitchen -> Living Room
//	locations[3].addConnection(&locations[1]); //Kitchen -> Hallway
//	locations[3].addConnection(&locations[9]); //Kitchen -> Garage
//	locations[9].addConnection(&locations[3]); //Garage -> Kitchen
//	locations[9].addConnection(&locations[7]); //Garage -> Back Garden
//	locations[9].addConnection(&locations[6]); //Garage -> Front Garden
//
//
//
//
//}
//
//Location* Game::getCurrentLocation()
//{
//	return pCurrentLocation;
//}
