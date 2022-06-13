#include "Zoo.hpp"

const std::vector<std::pair<InputType, Action>> Zoo::inputToAction = {
    {InputType::BUY, Zoo::buyAnimal},

};

int Zoo::startSimulation()
{
	std::string text;
	std::ifstream file(_testFileName);
	getline(file, text);

	if (setBudget(text) == false)
	{
		std::cout << "Unable to start simulation, budget not fixed" << std::endl;
		return EXIT_FAILURE;
	}

	while (getline(file, text))
	{
		const std::vector<std::string> &inputs = Determine::splitStringBy(text, ' ');
		InputType action;

		// If line start with '#' its a command in the input file
		if (text[0] == '#' || text == "")
		{
			continue;
		}

		action = Determine::determineInput(inputs[0]);
		switch (action)
		{
		case InputType::BUY:
			buyAnimal(inputs);
			break;
		case InputType::SELL:
			sellAnimal(inputs);
		case InputType::PASS:
			passDays(inputs);
			break;
		case InputType::UNKNOWN:
			std::cout << "Unknow instruction: \"" << inputs[0] << "\", ignoring" << std::endl;
			break;
		}
	}
	file.close();
	return EXIT_SUCCESS;
}

Animal *Zoo::buyChicken(const std::vector<std::string> &, bool isMale)
{
	return nullptr;
}

Animal *Zoo::buyTiger(const std::vector<std::string> &, bool isMale)
{
	return nullptr;
}

Animal *Zoo::buyEagle(const std::vector<std::string> &parameters, bool isMale)
{
	Age age;

	age = Determine::determineAge(parameters[3]);
	std::cout << "Buying new Eagle<" << ((isMale) ? "male" : "female")
		  << "> with " << age << std::endl;
	return new Eagle(age, isMale);
}

bool Zoo::buyAnimal(const std::vector<std::string> &parameters)
{
	Animal *newAnimal = nullptr;
	AnimalType type = Determine::determineAnimal(parameters[1]);
	bool isMale = false;

	Sex sexe = Determine::determineSex(parameters[2]);
	switch (sexe)
	{
	case Sex::MALE:
		isMale = true;
		break;
	case Sex::FEMALE:
		isMale = false;
		break;
	case Sex::UNKNOWN:
		std::cout << "[Warning] Unrecognized sex for animal : " << parameters[1] << ", can't buy" << std::endl;
		break;
	}

	switch (type)
	{
	case AnimalType::EAGLE:
		newAnimal = buyEagle(parameters, isMale);
		break;
	case AnimalType::CHICKEN:
		newAnimal = buyChicken(parameters, isMale);
		break;
	case AnimalType::TIGER:
		newAnimal = buyTiger(parameters, isMale);
		break;
	case AnimalType::UNKNOWN:
		std::cout << "[Warning] Unrecognized animal: " << parameters[1] << ", can't buy" << std::endl;
		break;
	}

	if (newAnimal == nullptr)
	{
		return false;
		// std::cout << "Unrecognized animal, ignoring instruction." << std::endl;
	}
	return true;
}

bool Zoo::sellAnimal(const std::vector<std::string> &parameters)
{
	return true;
	// std::cout << "Sell" << std::endl;
}

bool Zoo::passDays(const std::vector<std::string> &parameters)
{
	std::cout << "pass days:" << parameters[1] << std::endl;
	return true;
}

bool Zoo::setBudget(std::string text)
{
	if (text.compare(0, 7, "budget:") != 0)
		return false;

	float tmp = std::stof(text.substr(7, text.size() - 7));
	_accountant.initBudget(tmp);
	std::cout << "Zoo budget: " << tmp << std::endl;
	return true;
}

void Zoo::passADay() {}
