#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(), _type("WrongCat")
{
	std::cout << "Wrong Cat default constructor launched" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type), _type("WrongCat")
{
	std::cout << "Wrong Cat type constructor launched" << std::endl;
}

WrongCat::WrongCat(const WrongCat &animal) : WrongAnimal(animal), _type("WrongCat")
{
	std::cout << "Wrong Cat copy constructor launched" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &animal)
{
	if (this != &animal)
	{
		WrongAnimal::operator=(animal);
		_type = "WrongCat";
	}
	std::cout << "Wrong Cat assignment constructor launched" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor launched" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "The wrong cat is meowing" << std::endl;
}
