#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>


int main() {

    Intern i;

    Form* f;

    f = i.makeForm("RobotomyRequestForm", "hot bots");
    f = i.makeForm("ShrubberyCreationForm", "hot pots");
    f = i.makeForm("PresidentialPardonForm", "hot nots");
    f = i.makeForm("FakestForm", "F4k3lyf3");

    std::cout << "Done" << std::endl;
}