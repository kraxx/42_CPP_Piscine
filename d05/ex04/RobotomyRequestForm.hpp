#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form {

private:

    std::string const _target;
    static bool       _seeded;

    RobotomyRequestForm();

public:

    // Coplien methods

    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const& rhs);
    RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);
    ~RobotomyRequestForm() {};

    // Getters

    std::string const getTarget() const;
 
    // Methods

    void              execute(Bureaucrat const& executor) const;
};

std::ostream&         operator<<(std::ostream& output, RobotomyRequestForm const& rhs);

#endif