#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy {

public:

    SuperMutant();
    SuperMutant(SuperMutant const& rhs);
    SuperMutant&  operator=(SuperMutant const& rhs);
    ~SuperMutant();

    void takeDamage(int damage);
};

#endif