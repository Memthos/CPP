#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor launched" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor launched" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
	std::cout << "Animal copy constructor launched" << std::endl;
}

Animal&	Animal::operator=(const Animal &animal)
{
	if (this != &animal)
		_type = animal._type;
	std::cout << "Animal assignment constructor launched" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor launched" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}

void Animal::makeSound() const
{
	std::cout << "The animal is making sound" << std::endl;
}
