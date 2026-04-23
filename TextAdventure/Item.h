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

		bool isQuestItem() const;
		void setQuestItem(bool nQuestItem);

		std::string getName() const;
		std::string getDescription() const;
		void setName(std::string nName);
		void setDescription(std::string nDesc);
		int getScoreValue() const;
		void setScoreValue(int nScore);
		int getRecipeIndex() const;
		void setRecipeIndex(int nIndex);

		virtual std::string toString() const;
		virtual std::string getKeyID() const;
	};
}