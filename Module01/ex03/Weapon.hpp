#ifndef __WEAPON_H__
# define __WEAPON_H__

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
