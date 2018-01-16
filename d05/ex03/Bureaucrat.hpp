#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat {

private:

    std::string const _name;
    int               _grade;

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

    Bureaucrat();
    Bureaucrat(std::string const name, int grade);
    Bureaucrat(Bureaucrat const& rhs);
    Bureaucrat& operator=(Bureaucrat const& rhs);
    ~Bureaucrat() {};

    // Getters

    std::string const getName() const;
    int               getGrade() const;
 
    // Methods

    void              incrementGrade(int n);
    void              decrementGrade(int n);
    void              signForm(Form& form);
    void              executeForm(Form const& form);
};

std::ostream&         operator<<(std::ostream& output, Bureaucrat const& rhs);

#endif