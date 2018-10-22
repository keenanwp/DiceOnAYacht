#include "CategoryManager.h"
#include "Category.h"
#include "SumTitleCategory.h"
#include "SmallStraightCategory.h"
#include "AllDifferentCategory.h"
#include "AllSameCategory.h"
#include "NumberOfAKindCategory.h"
#include "FullHouseCategory.h"
#include "LargeStraightCategory.h"
#include "ChanceCategory.h"

CategoryManager::CategoryManager(int maxDiceValue)
	: _categories(CategoryName::ALL)
{
	_categories[CategoryName::ONES] = new SumTitleCategory(1);
	_categories[CategoryName::TWOS] = new SumTitleCategory(2);
	_categories[CategoryName::THREES] = new SumTitleCategory(3);
	_categories[CategoryName::FOURS] = new SumTitleCategory(4);
	_categories[CategoryName::FIVES] = new SumTitleCategory(5);
	_categories[CategoryName::SIXES] = new SumTitleCategory(6);
	_categories[CategoryName::SEVENS] = new SumTitleCategory(7);
	_categories[CategoryName::EIGHTS] = new SumTitleCategory(8);
	_categories[CategoryName::THREEOFAKIND] = new NumberOfAKindCategory(3, maxDiceValue);
	_categories[CategoryName::FOUROFAKIND] = new NumberOfAKindCategory(4, maxDiceValue);
	_categories[CategoryName::FULLHOUSE]	 = new FullHouseCategory(maxDiceValue);
	_categories[CategoryName::SMALLSTRAIGHT] = new SmallStraightCategory();
	_categories[CategoryName::LARGESTRAIGHT] = new LargeStraightCategory();
	_categories[CategoryName::ALLDIFFERENT] = new AllDifferentCategory(maxDiceValue);
	_categories[CategoryName::CHANCE] = new ChanceCategory();
	_categories[CategoryName::ALLSAME] = new AllSameCategory();
}


CategoryManager::~CategoryManager()
{
	for (auto it = _categories.begin(); it != _categories.end(); ++it)
		delete *it;

	_categories.clear();
}

int CategoryManager::GetCategoryScore(CategoryName categoryName, const std::vector<int>& diceRoll) const
{
	if (categoryName == CategoryName::ALL)
	{
		int maxScore = 0;
		for (auto it = _categories.begin(); it != _categories.end(); ++it)
		{
			int score = (*it)->Score(diceRoll);
			if (score > maxScore)
				maxScore = score;
		}

		return maxScore;
	}

	return _categories[categoryName]->Score(diceRoll);
}
