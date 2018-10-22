#pragma once

#include "Category.h"

class LargeStraightCategory :
	public Category
{
public:
	virtual int Score(const std::vector<int>& diceRoll);
};

