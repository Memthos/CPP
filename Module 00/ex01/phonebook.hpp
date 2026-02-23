#pragma once

#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook ();
		~PhoneBook ();

	private:
		Contact	_contacts[8];
		int		_maxContact;
};

#endif
