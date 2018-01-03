#include <iostream>
#include <stdlib.h>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) :
_name(name), _type(type) {
    if (type == "") {
        std::cerr << "Please assign a type before creating a zombie." << std::endl;
        exit(1);
    }
};

Zombie::Zombie() {};

Zombie::~Zombie() {
    std::cout << "<" << _name << " (" << _type << ")> huarghh... I am die" << std::endl;
};

void Zombie::announce() const {
    std::cout << "<" << _name << " (" << _type << ")> Braaiinnnsss..." << std::endl;
};
