#pragma once
#include <iostream>
#include <string>

namespace GameObject
{
	class Item
	{
	protected:
		std::string m_name;
		std::string m_description;
		bool m_questItem;
		int m_scoreValue;
		int m_recipeIndex;

	public:
		Item();
		Item(std::string nName, std::string nDescription, bool isQuest);

		bool isQuestItem();
		void setQuestItem(bool nQuestItem);

		std::string getName();
		std::string getDescription();
		void setName(std::string nName);
		void setDescription(std::string nDesc);
		int getScoreValue();
		void setScoreValue(int nScore);
		int getRecipeIndex();
		void setRecipeIndex(int nIndex);

		virtual std::string toString();
		virtual std::string getKeyID();
	};
}