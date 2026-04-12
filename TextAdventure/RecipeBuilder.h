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

		int score2DArray[5][5] = 
		{   //Build order
			{ 5, 0, 0, 0, 0 }, //Mug
			{ -1, 5, 5, 3, 1 },//Teabag
			{ -1, 5, 5, 3, 1 },//Sugar
			{ -1, 3, 3, 5, 2 },//Water
			{ -1, 1, 1, 2, 5 } //Milk
		};

	public:
		RecipeBuilder();
		RecipeBuilder(std::string nRecipeName);
		bool teaBuilder(Player& nPlayer, Quest& nQuest);
		bool teaBuilderMkII(Player& nPlayer, Quest& nQuest);
	};
}