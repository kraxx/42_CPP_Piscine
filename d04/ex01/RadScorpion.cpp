#include <iostream>
#include <string>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion() :
Enemy(80, "RadScorpion") {

    std::cout << "* click click click *" << std::endl;
};

RadScorpion::RadScorpion(RadScorpion const& rhs) {
    *this = rhs;
};

RadScorpion& RadScorpion::operator=(RadScorpion const& rhs) {

    _hp = rhs._hp;
    _type = rhs._type;
    return *this;
};

RadScorpion::~RadScorpion() {
    std::cout << "* SPROTCH *" << std::endl;
};