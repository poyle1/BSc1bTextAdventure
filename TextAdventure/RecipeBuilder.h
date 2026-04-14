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
		int m_recipeSteps;


		struct RecipeResults
		{
			int score;
			bool failed;
		};

		int score2DArray[6][6] = 
		{   //Build order
			{ 5, 0, 0, 0, 0, 0 }, //Mug
			{ -1, 5, 5, 3, 1, 0 },//Teabag
			{ -1, 5, 5, 3, 1, 0 },//Sugar
			{ -1, 3, 3, 5, 2, 1 },//Kettle(water)
			{ -1, 1, 1, 2, 5, 4 },//Milk
			{ -1, 0, 0, 1, 4, 5 } //Spoon
		};

	public:
		RecipeBuilder();
		RecipeBuilder(std::string nRecipeName, int nRecipeSteps);
		int getRecipeSteps() const;
		bool teaBuilderMkII(Player& nPlayer, Quest& nQuest);
	};
}