#ifndef PEON_HPP
# define PEON_HPP

# include <fstream>
# include <iostream>
# include <string>
# include "Victim.hpp"

class Peon : public Victim {

    Peon();

public:

    Peon(std::string name);
    Peon(Peon const& rhs);
    Peon& operator=(Peon const& rhs);
    ~Peon();

    void getPolymorphed() const;
};

#endif