#include "./Animals/AnimalType.hpp"
#include "./Animals/Age.hpp"
#include "./InputType.hpp"

class Determine
{
public:
	static InputType determineInput(std::string text)
	{
		if (text == "BUY")
		{
			return InputType::BUY;
		}
		else if (text == "SELL")
		{
			return InputType::SELL;
		}
		else if (text == "PASS")
		{
			return InputType::PASS;
		}
		return InputType::UNKNOWN;
	}

	static Sex determineSex(std::string text)
	{
		Sex animalSex = Sex::UNKNOWN;
		if (text == "male")
		{
			animalSex = Sex::MALE;
		}
		else if (text == "female")
		{
			animalSex = Sex::FEMALE;
		}
		else
		{
			std::cout << "Unrecognised Sex for animal" << std::endl;
		}
		return animalSex;
	}

	static Age determineAge(std::string text)
	{
		Age age;
		age._years = std::atoi(text.c_str());
		return age;
	}

	static AnimalType determineAnimal(std::string text)
	{
		if (text == "eagle")
		{
			return AnimalType::EAGLE;
		}
		else if (text == "tiger")
		{
			return AnimalType::TIGER;
		}
		else if (text == "chicken")
		{
			return AnimalType::CHICKEN;
		}
		return AnimalType::UNKNOWN;
	}

	static std::vector<std::string> splitStringBy(std::string text, char splitter)
	{
		std::vector<std::string> ret;
		int pos;
		while ((pos = text.find(splitter)) != std::string::npos)
		{
			ret.push_back(text.substr(0, pos));
			text = text.substr(pos + 1, text.size());
		}
		ret.push_back(text.substr(0, pos));
		return ret;
	}
};