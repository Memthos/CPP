#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &input) {
	*this = input;
}

Intern&	Intern::operator=(const Intern &input) {
	(void)input;
	return (*this);
}

Intern::~Intern() {}

static AForm*	createPresidential(std::string const &target) {
	return (new PresidentialPardonForm(target));
}
static AForm*	createRobotomy(std::string const &target) {
	return (new RobotomyRequestForm(target));
}
static AForm*	createShrubbery(std::string const &target) {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(std::string const &name, std::string const &target) {
	const std::string	names[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (*cmds[])(std::string const &target) = {&createPresidential, &createRobotomy, &createShrubbery};

	for (int i = 0; i < 3; i++) {
		if (names[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return (cmds[i](target));
		}
	}
	std::cout << "Intern couldn't create " << name << " form" << std::endl;
	return (NULL);
}
