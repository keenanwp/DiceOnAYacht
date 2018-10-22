#pragma once

#include <vector>

class Category
{
public:
	virtual ~Category() {};

	virtual int Score(const std::vector<int>& diceRoll) = 0;
};

