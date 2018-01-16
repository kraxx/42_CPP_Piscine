#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

private:

    std::string const _target;

    ShrubberyCreationForm();

public:

    // Coplien methods

    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const& rhs);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);
    ~ShrubberyCreationForm() {};

    // Getters

    std::string const getTarget() const;
 
    // Methods

    void              execute(Bureaucrat const& executor) const;
};

std::ostream&         operator<<(std::ostream& output, ShrubberyCreationForm const& rhs);

#endif