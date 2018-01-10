#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {

private:
    
    std::string _name;
    int         _ap;
    AWeapon*    _weapon;

    Character();

public:

    Character(std::string const& name);
    Character(Character const& rhs);
    Character&  operator=(Character const& rhs);
    ~Character();

    std::string getName() const;
    int         getAP() const;
    AWeapon*    getWeapon() const;

    void        recoverAP();
    void        equip(AWeapon* weapon);
    void        attack(Enemy* target);
};

std::ostream& operator<<(std::ostream& output, Character const& rhs);

#endif