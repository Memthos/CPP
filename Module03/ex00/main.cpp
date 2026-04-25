#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a("Bob");

	a.attack("Enemy");
	a.takeDamage(5);
	a.beRepaired(3);

	for (int i = 0; i < 12; i++)
		a.attack("Enemy");
}
