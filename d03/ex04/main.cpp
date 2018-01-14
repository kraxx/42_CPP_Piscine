#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main() {

    FragTrap a = FragTrap("ST3V3-0");
    FragTrap b = FragTrap("J0HNN13");
    FragTrap c(b);
    FragTrap d = FragTrap("B4M");
    d = c;

    ScavTrap sc = ScavTrap("Scavvie");

    a.meleeAttack("Brick");
    a.takeDamage(50);
    a.rangedAttack("Mordecai");
    a.takeDamage(40);
    a.vaulthunter_dot_exe("Lilith");
    ((ClapTrap)a).beRepaired(65);
    a.vaulthunter_dot_exe("Roland");
    a.takeDamage(1000);

    b.meleeAttack("Brick");
    b.takeDamage(90);
    b.rangedAttack("Mordecai");
    b.beRepaired(150);
    b.vaulthunter_dot_exe("Lilith");
    b.takeDamage(999);
    b.vaulthunter_dot_exe("Roland");
    b.takeDamage(1000);

    sc.challengeNewcomer("Jack");

    NinjaTrap nj = NinjaTrap("nerudo");
    nj.ninjaShoebox("susuk");



std::cout << "\n\n\n\n";



    SuperTrap st = SuperTrap("Alex Ezzeddine");
    st.meleeAttack("Tuktuk");
    st.rangedAttack("Putput");
    st.ninjaShoebox("Shoop");
    st.vaulthunter_dot_exe("Woopie");

    return 0;
};