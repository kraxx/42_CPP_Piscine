#include "Bureaucrat.hpp"
#include <iostream>
#include <string>


int main() {

    // Bureaucrat a("Small", -12);
    // Bureaucrat b("Large", 169);
    Bureaucrat c("Average Joe", 50);

    c.getName();
    c.getGrade();
    std::cout << c << std::endl;
    while (true) {
        try {
            c.incrementGrade(5);
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
            break;
        }
        std::cout << c << std::endl;
    }
    std::cout << "Done" << std::endl;
}