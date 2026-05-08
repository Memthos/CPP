#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
	std::cout << "Animal default constructor launched" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor launched" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	*this = animal;
	std::cout << "Animal copy constructor launched" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal &animal)
{
	if (this != &animal)
		_type = animal._type;
	std::cout << "Animal assignment constructor launched" << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor launched" << std::endl;
}

std::string AAnimal::getType() const
{
	return (_type);
}
