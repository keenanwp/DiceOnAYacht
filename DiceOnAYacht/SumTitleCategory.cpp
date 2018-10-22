#include "SumTitleCategory.h"



SumTitleCategory::SumTitleCategory(int titleNum)
	: _titleNum(titleNum)
{
}


int SumTitleCategory::Score(const std::vector<int>& diceRoll)
{
	int score = 0;
	for (auto it = diceRoll.cbegin(); it != diceRoll.cend(); ++it)
	{
		if (*it == _titleNum)
			score += _titleNum;
	}

	return score;
}
