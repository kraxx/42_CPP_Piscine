#include <cstdlib>
#include <iostream>
#include <time.h>
#include "ZombieHorde.hpp"

bool ZombieHorde::_seeded = false;

const std::string ZombieHorde::_names[10] = {
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

const std::string ZombieHorde::_types[10] = {
    "crazy",
    "rager",
    "frothing",
    "seething",
    "banger",
    "quite mad",
    "dancer",
    "bro",
    "chill",
    "pretty dead"
};

ZombieHorde::ZombieHorde(int N) :
_num(N) {
    if (_seeded == false) {
        srand(time(NULL));
        _seeded = true;
    }
    _horde = new Zombie[N]();
    for (int i = 0; i < N; i++) {
        _horde[i] = randomChump();
    }
    std::cout << "Horde unleashed" << std::endl;
};

ZombieHorde::~ZombieHorde() {
    delete [] _horde;
    std::cout << "Zombie horde destroyed" << std::endl;
};

void ZombieHorde::announce() const {
    for (int i = 0; i < _num; i++) {
        _horde[i].announce();
    }
}

Zombie &ZombieHorde::randomChump() {
    std::string name = _names[rand() % 10];
    std::string type = _types[rand() % 10];
    Zombie *retZomb = new Zombie(name, type);
    return *retZomb;
};
