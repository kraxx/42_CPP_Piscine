#include <iostream>
#include <string>
#include "Human.hpp"

void Human::meleeAttack(std::string const &target) {
    std::cout << "Melee attack directed at " << target << std::endl;
};

void Human::rangedAttack(std::string const &target) {
    std::cout << "Ranged attack directed at " << target << std::endl;    
};

void Human::intimidatingShout(std::string const &target) {    
    std::cout << "Intimidating shout directed at " << target << std::endl;
};

void Human::action(std::string const &action_name, std::string const &target) {

    void (Human::*fp[3])(std::string const &target) = {
        &Human::meleeAttack,
        &Human::rangedAttack,
        &Human::intimidatingShout
    };

    const std::string actions[] = {
        "melee",
        "ranged",
        "shout"
    };

    for (int i = 0; i < 3; i++) {
        if (action_name == actions[i]) {
            (this->*fp[i])(target);
        }
    }


};
