#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class	Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		class	GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class	GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &input);
		Bureaucrat&	operator=(const Bureaucrat &input);
		~Bureaucrat();
		std::string const&	getName() const;
		int					getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &data);

#endif
