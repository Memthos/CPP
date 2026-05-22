#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>

# include "Bureaucrat.hpp"

class	Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &input);
		Form&	operator=(const Form &input);
		~Form();
		std::string const&	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void	beSigned(const Bureaucrat& input);
};

std::ostream&	operator<<(std::ostream &os, const Form &data);

#endif
