#include <fstream>
#include <iostream>
#include <string>
#include "Peon.hpp"

Peon::Peon() :
Victim("Anon") {};

Peon::Peon(std::string name) :
Victim(name) {
    // Victim::Victim(name);
    std::cout << "Zog zog." << std::endl;
};

Peon::Peon(Peon const& rhs) {
    *this = rhs;
};

Peon& Peon::operator=(Peon const& rhs) {

    _name = rhs._name;
    return *this;
};

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
};

void Peon::getPolymorphed() const {
    std::cout << _name << " has been turned into a pink pony !" << std::endl;
}