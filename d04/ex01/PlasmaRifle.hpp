#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <string>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:

    PlasmaRifle();
    PlasmaRifle(PlasmaRifle const& rhs);
    PlasmaRifle& operator=(PlasmaRifle const& rhs);
    ~PlasmaRifle();

    void attack() const;
};

#endif