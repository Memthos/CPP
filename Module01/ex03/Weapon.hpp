#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon
{
	public:
		Weapon(std::string name);
		const std::string	getType(void);
		void	setType(std::string name);
	private:
		std::string	_type;
};

#endif
