#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);
    Form importantForm("TPS Report", 50, 25);

    std::cout << importantForm << std::endl;

    intern.signForm(importantForm);
    boss.signForm(importantForm);

    std::cout << importantForm << std::endl;

    return 0;
}
