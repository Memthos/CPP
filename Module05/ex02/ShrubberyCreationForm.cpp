#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &input) : AForm(input), _target(input._target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &input) {
	if (this != &input)
	{
		AForm::operator=(input);
		_target = input._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::beExecuted(Bureaucrat const &executor) const {
	std::ofstream	outfile;

	(void)executor;
	outfile.open((_target + "_shrubbery").c_str());
	if (outfile.is_open() == false)
	{
		std::cout << "Failed to open outfile" << std::endl;
		return ;
	}
	outfile << TREE;
	outfile.close();
}

std::ostream&	operator<<(std::ostream &os, const ShrubberyCreationForm &data) {
	std::cout << "Form " << data.getName()
		<< "[signed: " << (data.getSigned() ? "yes" : "no")
		<< ", sign grade " << data.getSignGrade()
		<< ", exec grade " << data.getExecGrade()
		<< "]" << std::endl;
	return (os);
}
