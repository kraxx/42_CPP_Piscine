#include <iostream>
#include "Pony.hpp"

Pony::Pony(int age, std::string name, std::string owner) :
_age(age), _name(name), _owner(owner) {
    std::cout << "New Pony created! >> "
    << "Name: " << _name
    << ", Age: " << _age
    << ", Owner: " << _owner
    << std::endl;
};

Pony::~Pony() {
    std::cout << "Pony " << _name << " destroyed (and burned to the ground)!" << std::endl;
};