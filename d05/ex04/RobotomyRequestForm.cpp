#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "RobotomyRequestForm.hpp"

/***********************************************
************** ROBOTOMYREQUESTFORM *************
***********************************************/

bool RobotomyRequestForm::_seeded = false;

// Coplien methods

RobotomyRequestForm::RobotomyRequestForm(std::string target):
Form("RobotomyRequestForm", 72, 45), _target(target) {

    if (_seeded == false) {
        _seeded = true;
        srand(time(NULL));
    }
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& rhs):
Form(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExec()), _target(rhs._target) {
    *this = rhs;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
    
    Form::operator=(rhs);
    return *this;
}

// Getters

std::string const RobotomyRequestForm::getTarget() const {
    return _target;
}

// Methods

void              RobotomyRequestForm::execute(Bureaucrat const& executor) const {

    Form::execute(executor);
    if (rand() % 2) {
        std::cout << "* skrr skrr *" << std::endl;
    } else {
        std::cout << "* Failure to Drill *" << std::endl;        
    }
}

std::ostream&     operator<<(std::ostream& output, RobotomyRequestForm const& rhs) {
    output << "RobotomyRequestForm target: " << rhs.getTarget();
    return output;
}