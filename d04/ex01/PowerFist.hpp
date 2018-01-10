#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <string>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:

    PowerFist();
    PowerFist(PowerFist const& rhs);
    PowerFist& operator=(PowerFist const& rhs);
    ~PowerFist();

    void attack() const;
};

#endif