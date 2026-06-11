#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	/* Create the 3 forms and some Bureaucrats */

	ShrubberyCreationForm home_form("Home");
	RobotomyRequestForm morty_form("Morty");
	PresidentialPardonForm rick_form("Rick Sanchez");
	Bureaucrat mike("Mike", 150);
	Bureaucrat jon("Jon", 120);
	Bureaucrat steve("Steve", 3);

	/* Try to execute forms without being signed */
	{
		try
		{
			std::cout << mike << std::endl;
			std::cout << home_form << std::endl;
			std::cout << morty_form << std::endl;
			std::cout << rick_form << std::endl;
			mike.executeForm(home_form);
			mike.executeForm(morty_form);
			mike.executeForm(rick_form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Sign form and try to execute without enough grade */
	{
		try
		{
			std::cout << mike << std::endl;
			std::cout << jon << std::endl;
			std::cout << home_form << std::endl;
			std::cout << morty_form << std::endl;
			std::cout << rick_form << std::endl;
			home_form.beSigned(jon);
			mike.executeForm(home_form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Sign forms and execute them */
	{
		try
		{
			morty_form.beSigned(steve);
			rick_form.beSigned(steve);
			std::cout << home_form << std::endl;
			std::cout << morty_form << std::endl;
			std::cout << rick_form << std::endl;

			std::cout << "\n --------------------- \n\n";
			steve.executeForm(home_form);
			std::cout << "\n --------------------- \n\n";
			steve.executeForm(morty_form);
			std::cout << "\n --------------------- \n\n";
			steve.executeForm(rick_form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";


	return (0);
}
