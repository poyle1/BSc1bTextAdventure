#pragma once
#include <iostream>

namespace GameObject
{
	class Item
	{
	protected:
		std::string m_name;
		std::string m_description;
		bool m_questItem;

	public:
		Item();
		Item(std::string nName, std::string nDescription, bool isQuest);
		bool isQuestItem();

		std::string getName();
		std::string getDescription();
		void setName(std::string nName);
		void setDescription(std::string nDesc);

		virtual std::string toString();
		virtual std::string getKeyID();
	};
}

