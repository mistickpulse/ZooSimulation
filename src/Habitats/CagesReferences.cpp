
#include "CagesReferences.hpp"

const std::vector<CageReference> CagesReferenceList::_catalog = {
    // AnimalType, Capacity, buy price, sell price, death by overpopulation, proba de malaide (valeur excle / 365)
    {AnimalType::EAGLE, 4, 2000.0f, 500.0f, 1, 0.02739726027f},
    {AnimalType::TIGER, 2, 2000.0f, 500.0f, 1, 0.08219178082f},
    {AnimalType::CHICKEN, 10, 300.0f, 50.0f, 4, 0.01369863013f},
    {AnimalType::UNKNOWN, 0, 0, 0, 0, 0.0f},
};