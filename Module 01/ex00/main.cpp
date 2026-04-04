#include "Zombie.hpp"

int	main()
{
	Zombie *bar;

	randomChump("foo");
	bar = newZombie("bar");
	delete bar;
}
