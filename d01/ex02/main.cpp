#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main() {
    ZombieEvent ev = ZombieEvent();
    ev.setZombieType("crazy");
    Zombie *first = ev.newZombie("Heero");
    first->announce();

    ev.setZombieType("banger");
    Zombie *rand1 = ev.randomChump();
    Zombie *rand2 = ev.randomChump();
    Zombie *rand3 = ev.randomChump();
    Zombie *rand4 = ev.randomChump();
    ev.setZombieType("rager");
    Zombie *rand5 = ev.randomChump();
    Zombie *rand6 = ev.randomChump();
    Zombie *rand7 = ev.randomChump();
    Zombie *rand8 = ev.randomChump();
    Zombie *rand9 = ev.randomChump();
    Zombie *rand10 = ev.randomChump();

    delete first;
    delete rand1;
    delete rand2;
    delete rand3;
    delete rand4;
    delete rand5;
    delete rand6;
    delete rand7;
    delete rand8;
    delete rand9;
    delete rand10;

    return 0;
}