#include "phonebook.hpp"

int	int_len(int nb)
{
	if (nb < 10)
		return (1);
	return (1 + int_len(nb / 10));
}

int	is_empty(std::string str)
{
	int	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 9 && str[i] <= 13) && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

std::string	get_input(std::string cur)
{
	std::string	input;

	while (is_empty(input))
	{
		std::cout << cur;
		std::getline(std::cin, input);
	}
	return (input);
}

void	addUser(PhoneBook &list)
{
	Contact	user;

	std::cout << "\033[2J\033[1;1H";
	user.set_f_name(get_input("First Name : "));
	std::cout << std::endl;
	user.set_l_name(get_input("Last Name : "));
	std::cout << std::endl;
	user.set_n_name(get_input("Nickname : "));
	std::cout << std::endl;
	user.set_phone(get_input("Phone Number : "));
	std::cout << std::endl;
	user.set_secret(get_input("Darkest Secret : "));
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
	if (atoi(str.c_str()) > list.getMaxContact() - 1)
		return (0);
	if (atoi(str.c_str()) > list.getCurContact() - 1)
		return (0);
	return (1);
}

void	print_contacts(PhoneBook &list)
{
	int	i = 0;
	std::cout << "\033[2J\033[1;1H";
	while (i < list.getCurContact() && i < list.getMaxContact())
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
