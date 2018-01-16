#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Form.hpp"

class Intern {

public:

    // Exceptions

    class InvalidFormException : public std::exception {

    public:

        InvalidFormException() {};
        InvalidFormException(InvalidFormException const& rhs);
        InvalidFormException& operator=(InvalidFormException const& rhs);
        virtual ~InvalidFormException() throw() {};

        virtual const char* what() const throw();
    };

    // Coplien methods

    Intern() {};
    Intern(Intern const& rhs);
    Intern& operator=(Intern const& rhs);
    ~Intern() {};

    // Methods

    Form*             makeForm(std::string name, std::string target);
};

#endif