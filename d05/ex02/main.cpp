#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>


int main() {

    Bureaucrat             c("Average Joe", 1);
    ShrubberyCreationForm  s("shrubs");
    RobotomyRequestForm    r("bots");
    PresidentialPardonForm p("president");

    std::cout << c << std::endl;
    std::cout << s << std::endl;
    std::cout << r << std::endl;
    std::cout << p << std::endl;

    c.signForm(s);
    c.signForm(r);
    c.signForm(p);

    c.executeForm(s);
    c.executeForm(r);
    c.executeForm(p);

    PresidentialPardonForm n("Unsigned");
    Bureaucrat f("Forgetful Fred", 1);
    Bureaucrat l("Loser Larry", 150);

    std::cout << f << std::endl;
    std::cout << l << std::endl;
    std::cout << n << std::endl;
    
    l.executeForm(p);
    f.executeForm(n);

    std::cout << "Done" << std::endl;
}