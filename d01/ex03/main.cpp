#include <iostream>
#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int main() {
    ZombieHorde horde = ZombieHorde(10);
    horde.announce();
    std::cout << "Terminating program" << std::endl;
    return 0;
}