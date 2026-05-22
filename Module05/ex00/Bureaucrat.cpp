#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	_grade = grade;
	//Add exception
}

Bureaucrat::Bureaucrat(const Bureaucrat &input) {
	*this = input;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &input) {
	if (this != &input)
	{
		_grade = input._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const&	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrementGrade() {
	--_grade;
	//Add exception
}

void	Bureaucrat::decrementGrade() {
	++_grade;
	//Add exception
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data)
{
	os << data.getName() << " bureaucrat grade " << data.getGrade() << "." << std::endl;
	return (os);
}
