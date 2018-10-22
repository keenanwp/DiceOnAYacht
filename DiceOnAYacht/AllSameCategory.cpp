#include "AllSameCategory.h"



int AllSameCategory::Score(const std::vector<int>& diceRoll)
{
	int lastValue = 0;
	for (auto it = diceRoll.cbegin(); it != diceRoll.cend(); ++it)
	{
		int value = *it;
		if (lastValue != 0 && value != lastValue)
			return 0;

		lastValue = value;
	}

	return 50;
}
