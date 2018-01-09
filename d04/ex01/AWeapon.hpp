#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <fstream>
# include <iostream>
# include <string>
# include "Victim.hpp"

class AWeapon {

private:
    
    std::string _name;
    std::string _title;

    AWeapon();

public:

    AWeapon(std::string name, std::string title);
    AWeapon(AWeapon const& rhs);
    AWeapon& operator=(AWeapon const& rhs);
    ~AWeapon();

    std::string getName() const;
    std::string getTitle() const;

    void polymorph(Victim const& target) const;
};

#endif

std::ostream& operator<<(std::ostream& output, AWeapon const& rhs);