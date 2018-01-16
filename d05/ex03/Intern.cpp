#include <iostream>
#include <string>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*****************************************
************** EXCEPTIONS ****************
*****************************************/

Intern::InvalidFormException::InvalidFormException(InvalidFormException const& rhs) {
    *this = rhs;
};

Intern::InvalidFormException& Intern::InvalidFormException::operator=(InvalidFormException const& rhs) {
    (void)rhs;
    return *this;
};

const char* Intern::InvalidFormException::what() const throw() {
    return "Exception: Invalid Form Type";
}

/*****************************************
***************** INTERN *****************
*****************************************/

// Coplien methods

Intern::Intern(Intern const& rhs) {
    *this = rhs;
}

Intern& Intern::operator=(Intern const& rhs) {

    (void)rhs;
    return *this;
}

// Methods

Form*   Intern::makeForm(std::string name, std::string target) {

    try {
        if (name == "ShrubberyCreationForm") {

            std::cout << "Intern creates " << name << std::endl;
            return new ShrubberyCreationForm(target);

        } else if (name == "RobotomyRequestForm") {

            std::cout << "Intern creates " << name << std::endl;
            return new RobotomyRequestForm(target);

        } else if (name == "PresidentialPardonForm") {

            std::cout << "Intern creates " << name << std::endl;
            return new PresidentialPardonForm(target);
        } else {

            throw InvalidFormException();
        }        
    } catch(std::exception& e) {

        std::cerr << "Intern could not create form; " << e.what() << std::endl;
    }

    return NULL;
};