#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &input) : ClapTrap(input)
{
	std::cout << "FragTrap " << input._name << " copy constructor called" << std::endl;
}

FragTrap	FragTrap::operator=(const FragTrap &input)
{
	if (this != &input)
	{
		ClapTrap::operator=(input);
	}
	std::cout << "FragTrap " << input._name << " copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " request a positive high five" << std::endl;
}
