#include "phonebook.hpp"

int	int_len(int nb)
{
	if (nb < 10)
		return (1);
	return (1 + int_len(nb / 10));
}

void	addUser(PhoneBook &list)
{
	std::string	input;
	Contact		user;

	std::cout << "\033[2J\033[1;1H";
	std::cout << "First Name : ";
	std::getline(std::cin, input);
	user.set_f_name(input);
	std::cout << std::endl << "Last Name : ";
	std::getline(std::cin, input);
	user.set_l_name(input);
	std::cout << std::endl << "Nickname : ";
	std::getline(std::cin, input);
	user.set_n_name(input);
	std::cout << std::endl << "Phone Number : ";
	std::getline(std::cin, input);
	user.set_phone(input);
	std::cout << std::endl << "Darkest Secret : ";
	std::getline(std::cin, input);
	user.set_secret(input);
	std::cout << std::endl;
	list.addContact(user);
}

void	print_search(std::string data)
{
	int	j;

	j = 0;
	if (data.length() > 9)
	{
		while (data[j] && j < 9)
		{
			std::cout << data[j];
			j++;
		}
		std::cout << ".";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << data;
	}
}
int	valid_input(std::string str, PhoneBook &list)
{
	int	i = 0;

	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	if (atoi(str.c_str()) > list.getCurContact() - 1)
		return (0);
	return (1);
}

void	print_contacts(PhoneBook &list)
{
	int	i = 0;
	std::cout << "\033[2J\033[1;1H";
	while (i < list.getCurContact())
	{
		std::cout << std::setw(10);
		std::cout << i;
		std::cout << "|";
		print_search(list.getContact(i).get_f_name());
		std::cout << "|";
		print_search(list.getContact(i).get_l_name());
		std::cout << "|";
		print_search(list.getContact(i).get_n_name());
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
}

void	search(PhoneBook &list)
{
	int			input_nb;
	std::string	input;

	print_contacts(list);
	while (1)
	{
		std::cout << "INDEX    |    EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		print_contacts(list);
		if (!valid_input(input, list))
			continue ;
		input_nb = std::atoi(input.c_str());
		std::cout << "First Name : " << list.getContact(input_nb).get_f_name() << std::endl;
		std::cout << "Last Name : " << list.getContact(input_nb).get_l_name() << std::endl;
		std::cout << "Nickname : " << list.getContact(input_nb).get_n_name() << std::endl;
		std::cout << "Phone Number : " << list.getContact(input_nb).get_phone() << std::endl;
		std::cout << "Darkest Secret : " << list.getContact(input_nb).get_secret() << std::endl;
		std::cout << std::endl;
	}
}

int	main(void)
{
	PhoneBook	list;
	std::string	input;

	while (input != "EXIT")
	{
		std::cout << "\033[2J\033[1;1H";
		std::cout << "ADD    |    SEARCH    |    EXIT" << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			addUser(list);
		else if (input == "SEARCH")
			search(list);
	}
	std::cout << "\033[2J\033[1;1H";
}
