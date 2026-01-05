#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Location
{
private:
	string name;
	string description;
	vector <Location*> connections;

	//Location* prevLocation;
	//Location* nextLocation;

public:
	Location();
	Location(string nName, string nDesc);

	string getName();
	void setName(string nName);
	string getDescription();
	void setDescription(string nDesc);

	int getNumConnections(); ////int getHandSize();
	vector<Location*> getConnections(); //vector<Card> getHand();;

	Location* getConnection(int index); //Card getCard(int index);
	void addConnection(Location* nlocation); //void addCard(Card new_card);
	

	//Location* getNextLoc();
	//Location* getPrevLoc();

	bool hasNextLoc();
	bool hasPrevLoc();

	
};

