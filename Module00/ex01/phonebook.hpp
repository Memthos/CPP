#ifndef PHONEBOOK_H
# define PHONEBOOK_H

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
		int					_maxContact;
		int					_curContact;

	public:
		PhoneBook();
		int		getCurContact();
		int		getMaxContact();
		void	addContact(Contact user);
		Contact	getContact(int i);
};

#endif
