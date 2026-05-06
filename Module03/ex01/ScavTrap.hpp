#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& input);
		ScavTrap&	operator=(const ScavTrap& input);
		~ScavTrap();
		void		attack(const std::string& target);
		void		guardGate(void);
};

#endif
