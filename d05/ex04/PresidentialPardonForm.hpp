#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form {

private:

    std::string const _target;

    PresidentialPardonForm();

public:

    // Coplien methods

    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const& rhs);
    PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);
    ~PresidentialPardonForm() {};

    // Getters

    std::string const getTarget() const;
 
    // Methods

    void              execute(Bureaucrat const& executor) const;
};

std::ostream&         operator<<(std::ostream& output, PresidentialPardonForm const& rhs);

#endif