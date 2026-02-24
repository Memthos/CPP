#pragma once

#ifndef __CONTACT_H__
# define __CONTACT_H__

# include <iostream>

class Contact
{
	private:
		std::string	f_name;
		std::string	l_name;
		std::string	n_name;
		std::string	phone;
		std::string	secret;
	public:
		void		set_f_name(std::string arg);
		void		set_l_name(std::string arg);
		void		set_n_name(std::string arg);
		void		set_phone(std::string arg);
		void		set_secret(std::string arg);
		std::string	get_f_name(void);
		std::string	get_l_name(void);
		std::string	get_n_name(void);
		std::string	get_phone(void);
		std::string	get_secret(void);
};

#endif
