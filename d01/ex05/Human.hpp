#ifndef HUMAN_HPP
# define HUMAN_HPP

#include <string>
#include "Brain.hpp"

class Human {
    const Brain _brain;

public:
    Human();
    ~Human();
    std::string identify() const;
    const Brain &getBrain() const;
};

#endif