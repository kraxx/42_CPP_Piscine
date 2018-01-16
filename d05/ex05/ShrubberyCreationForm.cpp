#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "ShrubberyCreationForm.hpp"

/***********************************************
*********** SHRUBBERYCREATIONFORM **************
***********************************************/

// Coplien methods

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& rhs):
Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec()), _target(rhs._target) {
    *this = rhs;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
    
    Form::operator=(rhs);
    return *this;
}


// Getters

std::string const ShrubberyCreationForm::getTarget() const {
    return _target;
}

// Methods

void              ShrubberyCreationForm::execute(Bureaucrat const& executor) const {

    Form::execute(executor);

    std::ofstream output;
    output.open(_target + "_shrubbery");
    output << "/\\/\\/\\\n/\\/\\/\\\n/\\/\\/\\\n||||||" << std::endl;
}

std::ostream&     operator<<(std::ostream& output, ShrubberyCreationForm const& rhs) {
    output << "ShrubberyCreationForm target: " << rhs.getTarget();
    return output;
}