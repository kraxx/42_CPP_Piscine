#include <cstdlib>
#include <iostream>
#include <time.h>
#include "ZombieEvent.hpp"

bool ZombieEvent::_seeded = false;

const std::string ZombieEvent::_names[10] = {
    "Albert",
    "Bruno",
    "Calvin",
    "Dick",
    "Enis",
    "Frederick",
    "Gaylord",
    "Henry",
    "Isaac",
    "Jung"
};

ZombieEvent::ZombieEvent() {    
    if (_seeded == false) {
       srand(time(NULL));
       _seeded = true;
    }
    std::cout << "New zombie event initialized" << std::endl;
};

ZombieEvent::~ZombieEvent() {
    std::cout << "Zombie event destroyed" << std::endl;
};

void ZombieEvent::setZombieType(std::string type) {
    _type = type;
    std::cout << "Zombie type set to: " << type << std::endl;
};

Zombie *ZombieEvent::newZombie(std::string name) {
    return new Zombie(name, _type);
}

Zombie *ZombieEvent::randomChump() {
    std::string name = _names[rand() % 10];
    Zombie *retZombie = newZombie(name);
    retZombie->announce();
    return retZombie;
};