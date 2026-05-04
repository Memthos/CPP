#ifndef __HUMANB_H__
# define __HUMANB_H__

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon &weapon);
		void	attack(void);
	private:
		std::string	_name;
		Weapon	*_Weapon;
};

#endif
