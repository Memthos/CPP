#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << "Claptrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &input)
{
	std::cout << "Claptrap " << input._name << " copy constructor called" << std::endl;
	*this = input;
}

ClapTrap ClapTrap::operator=(const ClapTrap &input)
{
	if (this != &input)
	{
		_name = input._name;
		_health = input._health;
		_energy = input._energy;
		_damage = input._damage;
	}
	std::cout << "Claptrap " << input._name << " copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << _name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (_health <= 0)
		std::cout << "Claptrap " << _name << " can't attack (no health)" << std::endl;
	else if (_energy <= 0)
		std::cout << "Claptrap"  << _name << " can't attack (no energy)" << std::endl;
	else
	{
		--_energy;
		std::cout << "Claptrap " << _name << " attacks " << target
			<< ", causing " << _damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_health != 0 && _health < amount)
		_health = 0;
	else if (_health != 0)
		_health -= amount;
	std::cout << "Claptrap " << _name << " takes " << amount << " of damage!"
		<< " Health: " << _health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy <= 0)
		std::cout << "Claptrap"  << _name << " can't repair (no energy)" << std::endl;
	else
	{
		--_energy;
		_health += amount;
		std::cout << "Claptrap " << _name << " repairs " << amount
			<< " of health! Health: " << _health << std::endl;
	}
}
