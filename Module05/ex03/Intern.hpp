#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include <string>

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern {
	public:
		Intern();
		Intern(const Intern &input);
		Intern&	operator=(const Intern &input);
		~Intern();
		AForm*	makeForm(std::string const &name, std::string const &target);
};

#endif
