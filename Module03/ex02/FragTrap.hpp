#ifndef __FRAG_TRAP_H__
# define __FRAG_TRAP_H__

#include "ScavTrap.hpp"

class FragTrap : public ScavTrap
{
	public:
		FragTrap(std::string name);
		FragTrap	(const FragTrap& input);
		FragTrap	operator=(const FragTrap& input);
		~FragTrap();
		void	highFivesGuys(void);
};

#endif
