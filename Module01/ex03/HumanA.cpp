#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _Weapon(weapon)
{}

void HumanA::attack(void)
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_Weapon.getType() << std::endl;
}
