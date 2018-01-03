#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {
    static const std::string _names[10];
    static const std::string _types[10];
    Zombie                   *_horde;
    int                      _num;

public:
    ZombieHorde(int N);
    ~ZombieHorde();
    void announce() const;
    Zombie &randomChump();
};

#endif