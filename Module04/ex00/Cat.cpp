#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat default constructor launched" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	_type = "Cat";
	std::cout << "Cat type constructor launched" << std::endl;
}

Cat::Cat(const Cat &animal) : Animal(animal)
{
	_type = "Cat";
	std::cout << "Cat copy constructor launched" << std::endl;
}

Cat&	Cat::operator=(const Cat &animal)
{
	if (this != &animal)
	{
		Animal::operator=(animal);
		_type = "Cat";
	}
	std::cout << "Cat assignment constructor launched" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor launched" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "The cat is meowing" << std::endl;
}
