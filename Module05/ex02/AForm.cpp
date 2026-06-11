#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &input): _name(input._name), _signed(input._signed), _signGrade(input._signGrade), _execGrade(input._execGrade) {}

AForm& AForm::operator=(const AForm &input) {
	if (this != &input)
		_signed = input._signed;
	return (*this);
}

AForm::~AForm() {}

std::string const& AForm::getName() const {
	return (_name);
}

bool	AForm::getSigned() const {
	return (_signed);
}

int	AForm::getSignGrade() const {
	return (_signGrade);
}

int	AForm::getExecGrade() const {
	return (_execGrade);
}

std::ostream&	operator<<(std::ostream &os, const AForm &data) {
	std::cout << "Form " << data.getName()
		<< "[signed: " << (data.getSigned() ? "yes" : "no")
		<< ", sign grade " << data.getSignGrade()
		<< ", exec grade " << data.getExecGrade()
		<< "]" << std::endl;
	return (os);
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char*	AForm::FormNotSigned::what() const throw() {
	return ("Form isn't signed");
}

void	AForm::beSigned(const Bureaucrat& input) {
	if (input.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (_signed == false)
		throw FormNotSigned();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	beExecuted(executor);
}
