#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include <string>

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
	private:
		std::string	_name;
		Weapon	&_Weapon;
};

#endif
