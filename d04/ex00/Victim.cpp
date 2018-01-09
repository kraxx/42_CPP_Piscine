#include <fstream>
#include <iostream>
#include <string>
#include "Victim.hpp"

Victim::Victim() {};

Victim::Victim(std::string name) :
_name(name) {

    std::cout << "Some random victim called " << name << " just popped !" << std::endl;
};

Victim::Victim(Victim const& rhs) {
    *this = rhs;
};

Victim& Victim::operator=(Victim const& rhs) {

    _name = rhs._name;
    return *this;
};

Victim::~Victim() {
    std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
};

std::string Victim::getName() const {
    return _name;
};

void Victim::getPolymorphed() const {
    std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream& operator<<(std::ostream& output, Victim const& rhs) {

    output << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
    return output;
}