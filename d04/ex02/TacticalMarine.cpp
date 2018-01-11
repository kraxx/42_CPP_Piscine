#include <iostream>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
    std::cout << "Tactical Marine ready for battle" << std::endl;
};

TacticalMarine::TacticalMarine(TacticalMarine const& rhs) {

    std::cout << "Tactical Marine ready for battle" << std::endl;
    *this = rhs;
};

TacticalMarine& TacticalMarine::operator=(TacticalMarine const& rhs) {

    (void)rhs;
    return *this;
};

TacticalMarine::~TacticalMarine() {
    std::cout << "Aaargh ..." << std::endl;
};

ISpaceMarine* TacticalMarine::clone() const {
    return new TacticalMarine;
};

void             TacticalMarine::battleCry() const {
    std::cout << "For the holy PLOT !" << std::endl;
};

void             TacticalMarine::rangedAttack() const {
    std::cout << "* attacks with bolter *" << std::endl;
};
void             TacticalMarine::meleeAttack() const {    
    std::cout << "* attacks with chainsword *" << std::endl;
};