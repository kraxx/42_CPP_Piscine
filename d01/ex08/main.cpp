#include <iostream>
#include <string>
#include "Human.hpp"

int main() {
    Human human;
    human.action("melee", "Mark");
    human.action("ranged", "Renee");
    human.action("shout", "Shawn");
    return 0;
}