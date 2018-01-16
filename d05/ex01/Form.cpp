#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

/*****************************************
************** EXCEPTIONS ****************
*****************************************/

Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const& rhs) {
    *this = rhs;
};

Form::GradeTooHighException& Form::GradeTooHighException::operator=(GradeTooHighException const& rhs) {
    (void)rhs;
    return *this;
};

const char* Form::GradeTooHighException::what() const throw() {
    return "Exception: Grade too high";
}


Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const& rhs) {
    *this = rhs;
};

Form::GradeTooLowException& Form::GradeTooLowException::operator=(GradeTooLowException const& rhs) {
    (void)rhs;
    return *this;
};

const char* Form::GradeTooLowException::what() const throw() {
    return "Exception: Grade too low";
}

/*****************************************
******************* FORM  ****************
*****************************************/

// Coplien methods

Form::Form():
_name("Anon"), _gradeSign(69), _gradeExec(96), _signed(false) {}

Form::Form(std::string name, int gradeSign, int gradeExec):
_name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false) {

    if (gradeSign < 1 || gradeExec < 1) {
        throw Form::GradeTooHighException();
    } else if (gradeSign > 150 || gradeExec > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(Form const& rhs):
_name(rhs._name), _gradeSign(rhs._gradeSign), _gradeExec(rhs._gradeExec), _signed(rhs._signed) {
    *this = rhs;
}

Form& Form::operator=(Form const& rhs) {

    std::string& str = const_cast<std::string&>(_name);
    str = rhs._name;
    int& n = const_cast<int&>(_gradeSign);
    n = rhs._gradeSign;
    n = const_cast<int&>(_gradeSign);
    n = rhs._gradeExec;
    return *this;
}

// Getters

std::string const Form::getName() const {
    return _name;
}

int               Form::getGradeSign() const {
    return _gradeSign;
}

int               Form::getGradeExec() const {
    return _gradeExec;
}

bool              Form::getSigned() const {
    return _signed;
}


// Methods

void              Form::beSigned(Bureaucrat &b) {

    if (_gradeSign < b.getGrade()) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

std::ostream&     operator<<(std::ostream& output, Form const& rhs) {
    output << "Form Name: "<< rhs.getName() << "; Grade required to sign: " << rhs.getGradeSign() << "; Grade required to execute: " << rhs.getGradeExec();
    return output;
}