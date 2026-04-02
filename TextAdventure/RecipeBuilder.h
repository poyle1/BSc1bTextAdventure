#pragma once
#include <vector>
#include "Player.h"

namespace MilkAndSugar::Core
{
	class RecipeBuilder
	{
	private:
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
		bool testQuest(MilkAndSugar::Object::Player& nPlayer);
	};
}