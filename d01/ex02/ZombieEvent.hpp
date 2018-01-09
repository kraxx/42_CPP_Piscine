#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include "Zombie.hpp"

class ZombieEvent {
    static const std::string _names[10];
    static bool              _seeded;
    std::string              _type;

public:
    ZombieEvent();
    ~ZombieEvent();
    void   setZombieType(std::string type);
    Zombie *newZombie(std::string name);
    Zombie *randomChump();
};

#endif