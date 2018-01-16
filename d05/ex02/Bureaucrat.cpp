#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

/*****************************************
************** EXCEPTIONS ****************
*****************************************/

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const& rhs) {
    *this = rhs;
};

Bureaucrat::GradeTooHighException& Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const& rhs) {
    (void)rhs;
    return *this;
};

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Exception: Grade too high";
}


Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const& rhs) {
    *this = rhs;
};

Bureaucrat::GradeTooLowException& Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const& rhs) {
    (void)rhs;
    return *this;
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Exception: Grade too low";
}

/*****************************************
************** BUREAUCRAT ****************
*****************************************/

// Coplien methods

Bureaucrat::Bureaucrat():
_name("Anon"), _grade(69) {}

Bureaucrat::Bureaucrat(std::string const name, int grade):
_name(name) {

    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& rhs) {
    *this = rhs;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {

    std::string& str = const_cast<std::string&>(_name);
    str = rhs._name;
    _grade = rhs._grade;
    return *this;
}

// Getters

std::string const Bureaucrat::getName() const {
    return _name;
}

int               Bureaucrat::getGrade() const {
    return _grade;
}

// Methods

void              Bureaucrat::incrementGrade(int n) {

    if (_grade - n < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade -= n;
}

void              Bureaucrat::decrementGrade(int n) {

    if (_grade + n > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade += n;
}

void              Bureaucrat::signForm(Form &form) {

    try {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    } catch(std::exception& e) {
        std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void              Bureaucrat::executeForm(Form const& form) {

    try {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    } catch(std::exception& e) {
        std::cout << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
};

std::ostream&     operator<<(std::ostream& output, Bureaucrat const& rhs) {
    output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return output;
}
