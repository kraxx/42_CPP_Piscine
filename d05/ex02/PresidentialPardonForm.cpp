#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "PresidentialPardonForm.hpp"

/***********************************************
*********** PRESIDENTIALPARDONFORM *************
***********************************************/


// Coplien methods

PresidentialPardonForm::PresidentialPardonForm(std::string target):
Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& rhs):
Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec()), _target(rhs._target) {
    *this = rhs;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {

    Form::operator=(rhs);
    return *this;
}

// Getters

std::string const PresidentialPardonForm::getTarget() const {
    return _target;
}

// Methods

void              PresidentialPardonForm::execute(Bureaucrat const& executor) const {

    Form::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream&     operator<<(std::ostream& output, PresidentialPardonForm const& rhs) {
    output << "PresidentialPardonForm target: " << rhs.getTarget();
    return output;
}