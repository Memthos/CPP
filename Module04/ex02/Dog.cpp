#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	_type = "Dog";
	_Brain = new Brain();
	std::cout << "Dog default constructor launched" << std::endl;
}

Dog::Dog(std::string type) : AAnimal(type)
{
	_type = "Dog";
	_Brain = new Brain();
	std::cout << "Dog type constructor launched" << std::endl;
}

Dog::Dog(const Dog &animal) : AAnimal(animal)
{
	_type = "Dog";
	_Brain = new Brain(*animal._Brain);
	std::cout << "Dog copy constructor launched" << std::endl;
}

Dog&	Dog::operator=(const Dog &animal)
{
	if (this != &animal)
	{
		AAnimal::operator=(animal);
		_type = "Dog";
		delete _Brain;
		_Brain = new Brain(*animal._Brain);
	}
	std::cout << "Dog assignment constructor launched" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete _Brain;
	std::cout << "Dog destructor launched" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "The dog is barking" << std::endl;
}

Brain&	Dog::getBrain() const
{
	return (*_Brain);
}
