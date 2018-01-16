#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"
#include <iostream>
#include <string>


int main() {

    srand(time(nullptr));

    std::string names[] = {
        "Alfred",
        "Benny",
        "Charlie",
        "Dawn",
        "Earles",
        "Frederick",
        "Garry",
        "Heinz",
        "Ignacio",
        "Jak",
        "Kris",
        "Lam",
        "Mario",
        "Nein",
        "Oreo",
        "Pat",
        "Quincy",
        "Richard",
        "Steve",
        "Turk",
        "Urkel",
        "Violet",
        "Wayne",
        "Xavier",
        "Yennefer",
        "Zoey"
    };

    CentralBureaucracy c;

    for (int i = 0; i < 20; i++) {
        Bureaucrat tmp(names[rand() % 26], (rand() % 149) + 1);
        c.feedBureaucracy(tmp);
    }
    for (int i = 0; i < 100; i++) {
        c.queueUp(names[rand() % 26]);
    }

    std::cout << "Done" << std::endl;
}