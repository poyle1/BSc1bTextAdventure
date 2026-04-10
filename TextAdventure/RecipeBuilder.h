#pragma once
#include <vector>
#include <string>

namespace GameObject
{
	class Player;
	class Quest;

	class RecipeBuilder
	{
	private:
		std::string m_recipeName;

		enum Ingredient
		{
			Mug,
			Teabag,
			Sugar,
			Water,
			Milk
		};

		struct RecipeResults
		{
			int score;
			bool failed;
		};

	public:
		RecipeBuilder();
		RecipeBuilder(std::string nRecipeName);
		bool teaBuilder(Player& nPlayer, Quest& nQuest);
	};
}