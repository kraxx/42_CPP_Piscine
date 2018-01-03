#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {

    std::string _name;
    Weapon      *_weapon;

public:
    HumanB(std::string name);
    ~HumanB();
    void attack() const;
    void setWeapon(Weapon &weapon);
};

#endif