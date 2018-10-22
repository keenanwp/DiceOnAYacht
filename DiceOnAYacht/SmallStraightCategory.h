#pragma once

#include "Category.h"

class SmallStraightCategory :
	public Category
{
public:
	virtual int Score(const std::vector<int>& diceRoll);
};

