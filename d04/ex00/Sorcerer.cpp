#include <fstream>
#include <iostream>
#include <string>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {};

Sorcerer::Sorcerer(std::string name, std::string title) :
_name(name), _title(title) {

    std::cout << name << ", " << title << ", is born !" << std::endl;
};

Sorcerer::Sorcerer(Sorcerer const& rhs) {
    *this = rhs;
};

Sorcerer& Sorcerer::operator=(Sorcerer const& rhs) {

    _name = rhs._name;
    _title = rhs._title;
    return *this;
};

Sorcerer::~Sorcerer() {
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
};

std::string Sorcerer::getName() const {
    return _name;
};

std::string Sorcerer::getTitle() const {
    return _title;
};

void Sorcerer::polymorph(Victim const& target) const {
    target.getPolymorphed();
};

std::ostream& operator<<(std::ostream& output, Sorcerer const& rhs) {

    output << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
    return output;
}