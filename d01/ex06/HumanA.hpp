#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA {

    std::string _name;
    Weapon      &_weapon;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack() const;
    void setWeapon(Weapon &weapon);
};

#endif