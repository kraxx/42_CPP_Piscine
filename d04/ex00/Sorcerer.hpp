#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <fstream>
# include <iostream>
# include <string>
# include "Victim.hpp"

class Sorcerer {

private:
    
    std::string _name;
    std::string _title;

    Sorcerer();

public:

    Sorcerer(std::string name, std::string title);
    Sorcerer(Sorcerer const& rhs);
    Sorcerer& operator=(Sorcerer const& rhs);
    ~Sorcerer();

    std::string getName() const;
    std::string getTitle() const;

    void polymorph(Victim const& target) const;
};

std::ostream& operator<<(std::ostream& output, Sorcerer const& rhs);

#endif