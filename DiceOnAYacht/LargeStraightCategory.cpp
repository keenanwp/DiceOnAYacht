#include "LargeStraightCategory.h"



int LargeStraightCategory::Score(const std::vector<int>& diceRoll)
{
	int lastValue = 0;
	for (auto it = diceRoll.cbegin(); it != diceRoll.cend(); ++it)
	{
		int value = *it;
		if (lastValue != 0 && value != lastValue + 1)
			return 0;

		lastValue = value;
	}

	return 40;
}
