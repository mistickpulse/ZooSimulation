
#ifndef _ACOUNTABILITY
#define _ACOUNTABILITY

#include <utility>
#include "./Animals/Age.hpp"
#include "./Foods/FoodType.hpp"

using Date = Age;

enum class SEASON_TYPE
{
	HIGH,
	LOW
};

class Accountability
{
private:
	float _budget = 0.0f;
	Date _dateSinceSimuStarted;
	SEASON_TYPE _seasonType = SEASON_TYPE::LOW;

	std::vector<std::pair<FoodType, float>> _storedFood;

public:
	Accountability() {}

	void initBudget(float budget)
	{
		_budget = budget;
	}

	void processDay()
	{
		_dateSinceSimuStarted.addDay();
		// Entre mai et septembre (mai = 5e mois mais on part de 0 donc 4, pareil pour septembre)
		if (_dateSinceSimuStarted._months >= 4 && _dateSinceSimuStarted._months <= 8)
		{
			_seasonType = SEASON_TYPE::HIGH;
		}
		else
		{
			_seasonType = SEASON_TYPE::LOW;
		}
	}
};

#endif
