
#ifndef _EAGLE
#define _EAGLE

#include "./Animal.hpp"

class Eagle : public Animal
{
public:
	Eagle(Age age, bool male) : Animal(age, AnimalType::EAGLE, male, (male ? 0.25f : 0.3f), 10, 25)
	{
	}
	virtual float getBuyPrice() const
	{
		return 0.0f;
	};
	virtual float getSellPrice() const
	{
		return 0.0f;

	}; // Recuperer dans la classe enfant le prix de vente
};

#endif