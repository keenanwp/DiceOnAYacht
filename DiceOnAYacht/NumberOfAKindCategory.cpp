#include "NumberOfAKindCategory.h"



NumberOfAKindCategory::NumberOfAKindCategory(int numberOfAKind, int maxDiceValue)
	: _numberOfAKind(numberOfAKind), _maxDiceValue(maxDiceValue)
{
}

int NumberOfAKindCategory::Score(const std::vector<int>& diceRoll)
{
	int sum = 0;
	bool success = false;
	std::vector<int> counts(8, 0);

	for (auto it = diceRoll.cbegin(); it != diceRoll.cend(); ++it)
	{
		int value = *it;
		sum += value;

		if (++counts[value - 1] == _numberOfAKind)
			success = true;
	}

	return success ? sum : 0;
}
