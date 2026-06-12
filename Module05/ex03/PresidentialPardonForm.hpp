#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <exception>
# include <string>

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &input);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &input);
		~PresidentialPardonForm();
		void	beExecuted(Bureaucrat const &executor) const;
};

std::ostream&	operator<<(std::ostream &os, const PresidentialPardonForm &data);

#endif
