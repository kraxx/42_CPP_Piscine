#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <fstream>
# include <iostream>
# include <string>

class Victim {

protected:

    std::string _name;

    Victim();

public:

    Victim(std::string name);
    Victim(Victim const& rhs);
    Victim& operator=(Victim const& rhs);
    ~Victim();

    std::string getName() const;

    virtual void getPolymorphed() const;
};

std::ostream& operator<<(std::ostream& output, Victim const& rhs);

#endif


