#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	_curContact = 0;
}

int PhoneBook::getCurContact()
{
	return (_curContact);
}

void PhoneBook::addContact(Contact user)
{
	_contacts[_curContact % _maxContact] = user;
	_curContact++;
}

Contact PhoneBook::getContact(int i)
{
	return (_contacts[i]);
}
