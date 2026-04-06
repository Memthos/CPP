#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _Weapon(NULL)
{}

void HumanB::setWeapon(Weapon &weapon)
{
	_Weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	if (this->_Weapon)
		std::cout << (*this->_Weapon).getType() << std::endl;
	else
		std::cout << "nothing" << std::endl;
}
