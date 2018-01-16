#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>


int main() {

    Bureaucrat c("Average Joe", 50);
    Form       s("EzMode", 100, 100);
    std::cout << c << std::endl;
    std::cout << s << std::endl;

    c.signForm(s);


    Bureaucrat cc("Unlucky Paul", 50);
    Form       ss("HardMode", 1, 1);
    std::cout << cc << std::endl;
    std::cout << ss << std::endl;

    cc.signForm(ss);

    std::cout << "Done" << std::endl;
}