#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &input) : AForm(input), _target(input._target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &input) {
	if (this != &input)
	{
		AForm::operator=(input);
		_target = input._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::beExecuted(Bureaucrat const &executor) const {
	(void)executor;
	std::srand(std::time(NULL));
	int	rand = std::rand();
	std::cout << "Makes some drilling noises" << std::endl;
	if (rand % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << "'s robotomization failed" << std::endl;
}

std::ostream&	operator<<(std::ostream &os, const RobotomyRequestForm &data) {
	std::cout << "Form " << data.getName()
		<< "[signed: " << (data.getSigned() ? "yes" : "no")
		<< ", sign grade " << data.getSignGrade()
		<< ", exec grade " << data.getExecGrade()
		<< "]" << std::endl;
	return (os);
}
