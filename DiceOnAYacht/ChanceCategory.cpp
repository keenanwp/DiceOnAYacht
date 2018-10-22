#include "ChanceCategory.h"



int ChanceCategory::Score(const std::vector<int>& diceRoll)
{
	int sum = 0;
	for (auto it = diceRoll.cbegin(); it != diceRoll.cend(); ++it)
		sum += *it;

	return sum;
}
