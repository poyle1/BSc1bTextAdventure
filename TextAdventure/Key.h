#pragma once
#include "Item.h"

namespace MilkAndSugar::Object
{
	class Key : public Item
	{
	private:
		bool m_isKey;
		std::string m_keyID;

	public:
		Key();
		Key(std::string nName, std::string nDescription, bool nIsKey, std::string nKeyID);

		std::string toString() override;
		std::string getKeyID() override;
	};
}