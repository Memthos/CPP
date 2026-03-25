#pragma once

#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "contact.hpp"
# include <iostream>
# include <cctype>
# include <cstdlib>
# include <string>
# include <iomanip>

class PhoneBook
{
	private:
		Contact				_contacts[8];
		static const int	_maxContact = 8;
		int					_curContact;

	public:
		PhoneBook();
		int		getCurContact();
		void	addContact(Contact user);
		Contact	getContact(int i);
};

#endif
