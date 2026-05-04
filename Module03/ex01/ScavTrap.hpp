#ifndef __SCAV_TRAP_H__
# define __SCAV_TRAP_H__

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap	(const ScavTrap& input);
		ScavTrap	operator=(const ScavTrap& input);
		~ScavTrap();
		void		attack(const std::string& target);
		void		guardGate(void);
	private:
};

#endif
