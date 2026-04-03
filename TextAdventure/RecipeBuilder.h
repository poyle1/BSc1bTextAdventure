#pragma once
#include <vector>
#include "Player.h"
#include "Quest.h"

namespace MilkAndSugar::Core
{
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
		bool teaBuilder(MilkAndSugar::Object::Player& nPlayer, MilkAndSugar::Core::Quest nQuest);
	};
}