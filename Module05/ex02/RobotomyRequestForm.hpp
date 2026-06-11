#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string	_target;
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &input);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm &input);
		~RobotomyRequestForm();
		void	beExecuted(Bureaucrat const &executor) const;
};

std::ostream&	operator<<(std::ostream &os, const RobotomyRequestForm &data);

#endif
