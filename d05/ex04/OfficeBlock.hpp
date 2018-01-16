#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Form.hpp"

class OfficeBlock {

private:

    Bureaucrat* _signer;
    Bureaucrat* _executor;
    Intern*     _intern;

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
        virtual ~GradeTooLowException() throw() {};

        virtual const char* what() const throw();
    };

    // Coplien methods

    OfficeBlock();
    ~OfficeBlock() {};

    // Getters

    Bureaucrat* getSigner() const;
    Bureaucrat* getExecutor() const;
    Intern*     getIntern() const;
 
    // Methods

    void doBureaucracy(std::string name, std::string target);

};

#endif