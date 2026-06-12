#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>

# include "Bureaucrat.hpp"

class	AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
	public:
		class	GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class	GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class	FormNotSigned : public std::exception {
			public:
				const char*	what() const throw();
		};
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &input);
		AForm&	operator=(const AForm &input);
		virtual ~AForm();
		std::string const&	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void	beSigned(const Bureaucrat& input);
		void	execute(Bureaucrat const &executor) const;
		virtual void	beExecuted(Bureaucrat const &executor) const = 0;
};

std::ostream&	operator<<(std::ostream &os, const AForm &data);

#endif
