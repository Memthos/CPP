#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_health = FragTrap::_health;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &input) : ClapTrap(input), ScavTrap(input), FragTrap(input), _name(input._name)
{
	std::cout << "DiamondTrap " << input._name << " copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &input)
{
	if (this != &input)
	{
		ClapTrap::operator=(input);
		_name = input._name;
	}
	std::cout << "DiamondTrap " << input._name << " copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is: " << _name << ", "
		<< "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}
