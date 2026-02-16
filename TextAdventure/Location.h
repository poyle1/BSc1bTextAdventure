#pragma once
#include <vector>
#include <string>
using namespace std;

class Location
{
private:
	string name;
	string description;
	string flavorText;
	string entryText;
	string returnText;
	vector <Location*> connections; //Tree structure of locations using a vector of pointers
	bool visited;
	bool locked;

public:
	Location();
	Location(string nName, string nDescription, bool nLocked = false);
	//
	string getName();
	string getDescription();
	string getFlavorText();
	string getEntryText();
	//
	void setName(string nName);
	void setDescription(string nDesc);
	void setFlavorText(string nFlavorText);
	void setEntryText(string nEntryText);

	vector<Location*> getConnections(); //vector<Card> getHand();
	int getNumConnections(); ////int getHandSize();
	Location* getConnection(int index); //Card getCard(int index);
	void addConnection(Location* nLocation); //void addCard(Card new_card);
	void removeConnection(int index); //void removeCard(int index);
	void outputConnections(); //void outputHand();

	string getDisplayName();
	bool isLocked();
	void setLocked(bool state);	
};

