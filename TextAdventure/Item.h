#pragma once
#include <iostream>
using namespace std;

class Item
{
protected:
	string m_name;
	string m_description;
	bool m_questItem;
	
public:
	Item();
	Item(string nName, string nDescription, bool isQuest);
	bool isQuestItem();

	string getName();
	string getDescription();
	void setName(string nName);
	void setDescription(string nDesc);

	virtual string toString();
	virtual string getKeyID();
};
