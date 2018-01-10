#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy {

public:

    RadScorpion();
    RadScorpion(RadScorpion const& rhs);
    RadScorpion&  operator=(RadScorpion const& rhs);
    ~RadScorpion();
};

#endif