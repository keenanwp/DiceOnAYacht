#pragma once

#include "Category.h"

class ChanceCategory :
	public Category
{
public:
	virtual int Score(const std::vector<int>& diceRoll);
};

