#include <iostream>
#include "Human.hpp"

Human::Human() {};

Human::~Human() {};

std::string Human::identify() const {
    return _brain.identify();
};

const Brain &Human::getBrain() const {
    return _brain;
}