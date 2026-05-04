#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap	(const FragTrap& input);
		FragTrap	operator=(const FragTrap& input);
		~FragTrap();
		void	highFivesGuys(void);
};

#endif
