#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:

    std::string const _name;
    int const         _gradeSign;
    int const         _gradeExec;
    bool              _signed;

public:

    // Exceptions

    class GradeTooHighException : public std::exception {

    public:

        GradeTooHighException() {};
        GradeTooHighException(GradeTooHighException const& rhs);
        GradeTooHighException& operator=(GradeTooHighException const& rhs);
        virtual ~GradeTooHighException() throw() {};

        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {

    public:

        GradeTooLowException() {};
        GradeTooLowException(GradeTooLowException const& rhs);
        GradeTooLowException& operator=(GradeTooLowException const& rhs);
        virtual ~GradeTooLowException() throw() {};

        virtual const char* what() const throw();
    };

    // Coplien methods

    Form();
    Form(std::string name, int gradeSign, int gradeExec);
    Form(Form const& rhs);
    Form& operator=(Form const& rhs);
    ~Form() {};

    // Getters

    std::string const getName() const;
    int               getGradeSign() const;
    int               getGradeExec() const;
    bool              getSigned() const;

    // Methods

    void              beSigned(Bureaucrat& b);
};

std::ostream&   operator<<(std::ostream& output, Form const& rhs);

#endif