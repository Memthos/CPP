#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &input) : AForm(input), _target(input._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &input) {
	if (this != &input)
	{
		AForm::operator=(input);
		_target = input._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::beExecuted(Bureaucrat const &executor) const {
	(void)executor;
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream&	operator<<(std::ostream &os, const PresidentialPardonForm &data) {
	std::cout << "Form " << data.getName()
		<< "[signed: " << (data.getSigned() ? "yes" : "no")
		<< ", sign grade " << data.getSignGrade()
		<< ", exec grade " << data.getExecGrade()
		<< "]" << std::endl;
	return (os);
}
