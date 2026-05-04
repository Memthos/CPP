#ifndef __CLAP_TRAP_H__
# define __CLAP_TRAP_H__

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap	(const ClapTrap& input);
		ClapTrap	operator=(const ClapTrap& input);
		~ClapTrap();
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
	protected:
		std::string		_name;
		unsigned int	_health;
		unsigned int	_energy;
		unsigned int	_damage;
};

#endif
