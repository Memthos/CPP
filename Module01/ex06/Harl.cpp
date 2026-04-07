#include "Harl.hpp"

static int	getValue(std::string level)
{
	int		i = 0;
	t_func functions[] = {
	{"DEBUG", 1},
	{"INFO", 2},
	{"WARNING", 3},
	{"ERROR", 4}};

	while (i < 4)
	{
		if (functions[i].type == level)
		{
			return (functions[i].idx);
		}
		i++;
	}
	return (0);
}

void Harl::complain(std::string level)
{
	switch (getValue(level))
	{
		default:
		{
			this->other();
			break ;
		}
		case 1:
			this->debug();
		case 2:
			this->info();
		case 3:
			this->warning();
		case 4:
			this->error();
	}
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout <<  "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::other(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
