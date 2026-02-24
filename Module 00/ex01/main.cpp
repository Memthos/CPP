#include "phonebook.hpp"

void	addUser(PhoneBook &list)
{
	std::string	input;
	Contact		user;

	std::cout << "\033[2J\033[1;1H";
	std::cout << "First Name : ";
	std::cin >> input;
	user.set_f_name(input);
	std::cout << std::endl << "Last Name : ";
	std::cin >> input;
	user.set_l_name(input);
	std::cout << std::endl << "Nickname : ";
	std::cin >> input;
	user.set_n_name(input);
	std::cout << std::endl << "Phone Number : ";
	std::cin >> input;
	user.set_phone(input);
	std::cout << std::endl << "Darkest Secret : ";
	std::cin >> input;
	user.set_secret(input);
	std::cout << std::endl;
	list.addContact(user);
}

void	search(PhoneBook &list)
{
	int			i = 0;
	int			j;
	std::string	input;

	std::cout << "\033[2J\033[1;1H";
	std::cout << std::setw(10);
	while (i < list.getCurContact())
	{
		j = 0;
		while (list.getContact(i).get_f_name()[j] && j < 9)
			std::cout << list.getContact(i).get_f_name()[j++];
		if (list.getContact(i).get_f_name()[j])
			std::cout << ".";
		std::cout << " | ";
		j = 0;
		while (list.getContact(i).get_l_name()[j] && j < 9)
			std::cout << list.getContact(i).get_l_name()[j++];
		if (list.getContact(i).get_l_name()[j])
			std::cout << ".";
		std::cout << " | ";
		j = 0;
		while (list.getContact(i).get_n_name()[j] && j < 9)
			std::cout << list.getContact(i).get_n_name()[j++];
		if (list.getContact(i).get_n_name()[j])
			std::cout << ".";
		std::cout << " | ";
		j = 0;
		while (list.getContact(i).get_phone()[j] && j < 9)
			std::cout << list.getContact(i).get_phone()[j++];
		if (list.getContact(i).get_phone()[j])
			std::cout << ".";
		std::cout << " | ";
		j = 0;
		while (list.getContact(i).get_secret()[j] && j < 9)
			std::cout << list.getContact(i).get_secret()[j++];
		if (list.getContact(i).get_secret()[j])
			std::cout << ".";
		std::cout << std::endl;
		i++;
	}
	std::cin >> input;
	if (input == "EXIT")
		return ;
}

int	main(void)
{
	PhoneBook	list;
	std::string	cmd;

	while (cmd != "EXIT")
	{
		std::cout << "\033[2J\033[1;1H";
		std::cout << "ADD    |    SEARCH    |    EXIT" << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			addUser(list);
		else if (cmd == "SEARCH")
			search(list);
	}
	std::cout << "\033[2J\033[1;1H";
}
