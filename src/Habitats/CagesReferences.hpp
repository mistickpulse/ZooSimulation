
#ifndef _CAGE_REF_
#define _CAGE_REF_

#include <vector>
#include <utility>
#include <string>
#include "../Foods/FoodType.hpp"
#include "../Animals/AnimalType.hpp"

class CageReference // On peux faire une struct ici a la place mais flemme lmao
{
public:
	AnimalType Cagetype;
	int capacity;
	float priceBuy;
	float priceSell;
	int lossByOverpopulate;
	float sicknessProba;
};

class CagesReferenceList
{
	static const std::vector<CageReference> _catalog;

	static const CageReference &getCageByAnimal(AnimalType type)
	{
		for (const auto &cageRef : _catalog)
		{
			if (type == cageRef.Cagetype)
				return cageRef;
		}
		return getCageByAnimal(AnimalType::UNKNOWN);
	}
};

#endif