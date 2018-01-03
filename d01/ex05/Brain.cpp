#include <iostream>
#include <sstream>
#include "Brain.hpp"

Brain::Brain() {};

Brain::~Brain() {};

std::string Brain::identify() const {
    std::stringstream buf;
    buf << this;
    return buf.str();
};