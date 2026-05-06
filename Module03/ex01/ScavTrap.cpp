#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &input) : ClapTrap(input)
{
	std::cout << "ScavTrap " << input._name << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &input)
{
	if (this != &input)
		ClapTrap::operator=(input);
	std::cout << "ScavTrap " << input._name << " copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (_health <= 0)
		std::cout << "ScavTrap " << _name << " can't attack (no health)" << std::endl;
	else if (_energy <= 0)
		std::cout << "ScavTrap"  << _name << " can't attack (no energy)" << std::endl;
	else
	{
		--_energy; 
		std::cout << "ScavTrap " << _name << " attacks " << target
			<< ", causing " << _damage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode" << std::endl;
}
