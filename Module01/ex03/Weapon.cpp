#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->setType(name);
}

const std::string Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string name)
{
	this->_type = name;
}
