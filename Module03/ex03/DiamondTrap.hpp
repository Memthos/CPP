#ifndef DIAMOND_TRAP_H
# define DIAMOND_TRAP_H

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap	(const DiamondTrap& input);
		DiamondTrap	operator=(const DiamondTrap& input);
		~DiamondTrap();
		void	attack(const std::string& target);
		void	whoAmI();
	private:
		std::string	_name;
};

#endif
