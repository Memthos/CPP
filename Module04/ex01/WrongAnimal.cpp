#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "Wrong Animal default constructor launched" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "Wrong Animal type constructor launched" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	*this = animal;
	std::cout << "Wrong Animal copy constructor launched" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal &animal)
{
	if (this != &animal)
		_type = animal._type;
	std::cout << "Wrong Animal assignment constructor launched" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor launched" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "The wrong animal is making sound" << std::endl;
}
