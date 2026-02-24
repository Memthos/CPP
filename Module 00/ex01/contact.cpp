#include "contact.hpp"

void	Contact::set_f_name(std::string arg)
{
	this->f_name = arg;
}
void	Contact::set_l_name(std::string arg)
{
	this->l_name = arg;
}
void	Contact::set_n_name(std::string arg)
{
	this->n_name = arg;
}
void	Contact::set_phone(std::string arg)
{
	this->phone = arg;
}
void	Contact::set_secret(std::string arg)
{
	this->secret = arg;
}

std::string	Contact::get_f_name(void)
{
	return (this->f_name);
}
std::string	Contact::get_l_name(void)
{
	return (this->l_name);
}
std::string	Contact::get_n_name(void)
{
	return (this->n_name);
}
std::string	Contact::get_phone(void)
{
	return (this->phone);
}
std::string	Contact::get_secret(void)
{
	return (this->secret);
}
