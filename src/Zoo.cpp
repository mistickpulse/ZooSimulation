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
		if (text[0] == '#')
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
			std::cout << "Unknow instruction: " << inputs[0] << ", ignoring" << std::endl;
			break;
		}
	}
	file.close();
	return EXIT_SUCCESS;
}

Animal *Zoo::buyEagle(std::string text)
{
	bool male;
	Age age;
	const auto &tmp = Determine::splitStringBy(text, ' ');

	Sex sexe = Determine::determineSex(tmp[1]);
	if (sexe == Sex::UNKNOWN)
	{
		return nullptr;
	}
	age = Determine::determineAge(tmp[2]);
	std::cout << "Buying new Eagle<" << ((male) ? "male" : "female")
		  << "> with age :" << age._years << std::endl;
	return new Eagle(age, male);
}

bool Zoo::buyAnimal(const std::vector<std::string> &parameters)
{
	Animal *newAnimal = nullptr;
	AnimalType type = Determine::determineAnimal(parameters[1]);
	switch (type)
	{
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
	// std::cout << "pass days" << std::endl;
	return true;
}

bool Zoo::setBudget(std::string text)
{
	if (text.compare(0, 7, "budget:") != 0)
		return false;

	budget = std::stof(text.substr(7, text.size() - 7));
	std::cout << "Zoo budget: " << budget << std::endl;
	return true;
}

void Zoo::passADay() {}
