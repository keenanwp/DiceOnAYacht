#include "AllDifferentCategory.h"



AllDifferentCategory::AllDifferentCategory(int maxDiceValue)
	: _maxDiceValue(maxDiceValue)
{
}

int AllDifferentCategory::Score(const std::vector<int>& diceRoll)
{
	std::vector<int> counts(_maxDiceValue, 0);

	for (auto it = diceRoll.cbegin(); it != diceRoll.cend(); ++it)
	{
		int index = *it - 1;
		if (counts[index] > 0)
			return 0;

		counts[index]++;
	}

	return 40;
}
