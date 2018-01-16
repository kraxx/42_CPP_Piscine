#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "OfficeBlock.hpp"
#include <iostream>
#include <string>


int main() {

    Bureaucrat a("Alfred", 50);
    Bureaucrat b("Benny", 5);
    Intern     i;

    OfficeBlock ob;

    ob.setSigner(a);
    // ob.setExecutor(b);
    ob.setIntern(i);

    try {
        ob.doBureaucracy("RobotomyRequestForm", "BeepBoop");
    } catch(std::exception& e) {
        std::cerr << "Error doing bureaucracy; " << e.what() << std::endl;
    }

    std::cout << "Done" << std::endl;
}