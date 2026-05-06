#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog default constructor launched" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	_type = "Dog";
	std::cout << "Dog type constructor launched" << std::endl;
}

Dog::Dog(const Dog &animal) : Animal(animal)
{
	_type = "Dog";
	std::cout << "Dog copy constructor launched" << std::endl;
}

Dog&	Dog::operator=(const Dog &animal)
{
	if (this != &animal)
	{
		Animal::operator=(animal);
		_type = "Dog";
	}
	std::cout << "Dog assignment constructor launched" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor launched" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "The dog is barking" << std::endl;
}
