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
	vector <Location*> connectionsVector;

public:
	Location();
	Location(string nName, string nDesc);

	string getName();
	void setName(string nName);
	string getDescription();
	void setDescription(string nDesc);
	string getFlavorText();
	void setFlavorText(string nFlavorText);
	string getEntryText();
	void setEntryText(string nEntryText);

	vector<Location*> getConnections(); //vector<Card> getHand();
	int getNumConnections(); ////int getHandSize();
	

	Location* getConnection(int index); //Card getCard(int index);

	void addConnection(Location* nLocation); //void addCard(Card new_card);
	void removeConnection(int index); //void removeCard(int index);

	void outputConnections();


	
};

