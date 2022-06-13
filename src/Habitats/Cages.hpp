
#ifndef _CAGES
#define _CAGES

#include <vector>
#include "../Animals/Animal.hpp"
#include "../Animals/AnimalType.hpp"
#include "./CagesReferences.hpp"

// Forward declaration pour les erreur de compil

class Cages
{
private:
	const CageReference &_cageRef;
	std::vector<Animal *> _animals; // All the stored animals in the cage

public:
	Cages(const CageReference &cageRef) : _cageRef{cageRef} {};
	void addAnimal(Animal *newAnimal)
	{
		_animals.push_back(newAnimal);
	}
};

#endif