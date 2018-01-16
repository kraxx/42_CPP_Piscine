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

    i.makeForm("RobotomyRequestForm", "hot bots");
    i.makeForm("ShrubberyCreationForm", "hot pots");
    i.makeForm("PresidentialPardonForm", "hot nots");
    i.makeForm("FakestForm", "F4k3lyf3");

    std::cout << "Done" << std::endl;
}