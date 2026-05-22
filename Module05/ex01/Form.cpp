#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1 || _signGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &input): _name(input._name), _signed(input._signed), _signGrade(input._signGrade), _execGrade(input._execGrade) {}

Form& Form::operator=(const Form &input) {
	if (this != &input)
		_signed = input._signed;
	return (*this);
}

Form::~Form() {}

std::string const& Form::getName() const {
	return (_name);
}

bool	Form::getSigned() const {
	return (_signed);
}

int	Form::getSignGrade() const {
	return (_signGrade);
}

int	Form::getExecGrade() const {
	return (_execGrade);
}

std::ostream&	operator<<(std::ostream &os, const Form &data) {
	std::cout << "Form " << data.getName()
		<< "[signed: " << (data.getSigned() ? "yes" : "no")
		<< ", sign grade " << data.getSignGrade()
		<< ", exec grade " << data.getExecGrade()
		<< "]" << std::endl;
	return (os);
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

void	Form::beSigned(const Bureaucrat& input) {
	if (input.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}
