#include "FullHouseCategory.h"



FullHouseCategory::FullHouseCategory(int maxDiceValue)
	: _maxDiceValue(maxDiceValue)
{
}

int FullHouseCategory::Score(const std::vector<int>& diceRoll)
{
	bool threeOfAKind = false;
	bool twoOfAKind = false;
	std::vector<int> counts(_maxDiceValue, 0);

	for (auto it = diceRoll.cbegin(); it != diceRoll.cend(); ++it)
		++counts[*it - 1];

	for (auto it = counts.cbegin(); it != counts.cend(); ++it)
	{
		if (*it == 3)
			threeOfAKind = true;
		else if (*it == 2)
			twoOfAKind = true;
	}

	return threeOfAKind && twoOfAKind ? 25 : 0;
}
