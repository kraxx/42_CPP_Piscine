#include <iostream>
#include "Pony.hpp"

void ponyOnTheStack(int age, std::string name, std::string owner) {    
    Pony stack = Pony(age, name, owner);
}

Pony *ponyOnTheHeap(int age, std::string name, std::string owner) {
    Pony *heap = new Pony(age, name, owner);
    return heap;
}

int main() {
    Pony *heap = ponyOnTheHeap(10, "Heapbro", "Heapdude");
    ponyOnTheStack(69, "Stackguy", "Stackmaster");
    delete heap;
    std::cout << "Terminating program." << std::endl;
    return 0;    
}