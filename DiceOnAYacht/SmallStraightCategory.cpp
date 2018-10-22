#include "SmallStraightCategory.h"



int SmallStraightCategory::Score(const std::vector<int>& diceRoll)
{
	int straightCount = 0;
	int lastValue = 0;
	for (auto it = diceRoll.cbegin(); it != diceRoll.cend(); ++it)
	{
		int value = *it;
		if (lastValue == 0 || value == lastValue + 1)
		{
			if (++straightCount == 4)
				return 30;
		}
		else
			straightCount = 0;

		lastValue = value;
	}

	return 0;
}
