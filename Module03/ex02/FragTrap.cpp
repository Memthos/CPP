#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ScavTrap(name)
{
	_energy = 100;
	_damage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &input) : ScavTrap(input)
{
	std::cout << "FragTrap " << input._name << " copy constructor called" << std::endl;
}

FragTrap	FragTrap::operator=(const FragTrap &input)
{
	if (this != &input)
	{
		ScavTrap::operator=(input);
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
	std::cout << "FragTrap " << _name << " request a positive high-fives" << std::endl;
}
