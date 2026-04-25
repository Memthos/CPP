#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _health(10), _energy(10), _damage(0)
{
	std::cout << "Claptrap default constructor called" << std::endl;
}

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
	std::cout << "Claptrap " << input._name << " copy assignment operator called" << std::endl;
	if (this != &input)
	{
		this->_name = input._name;
		this->_health = input._health;
		this->_energy = input._energy;
		this->_damage = input._damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap " << this->_name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_health <=0)
		std::cout << "Claptrap " << this->_name << " can't attack (no health)" << std::endl;
	else if (this->_energy <= 0)
		std::cout << "Claptrap"  << this->_name << " can't attack (no energy)" << std::endl;
	else
	{
		--this->_energy;
		std::cout << "Claptrap " << this->_name << " attacks " << target
			<< ", causing " << this->_damage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health != 0 && this->_health < amount)
		this->_health = 0;
	else if (this->_health != 0)
		this->_health -= amount;
	std::cout << "Claptrap " << this->_name << " takes " << amount << " of damage!"
		<< " Health: " << this->_health << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy <= 0)
		std::cout << "Claptrap"  << this->_name << " can't repair (no energy)" << std::endl;
	else
	{
		--this->_energy;
		this->_health += amount;
		std::cout << "Claptrap " << this->_name << " repairs " << amount
			<< " of health! Health: " << this->_health << std::endl;
	}
}
