#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    std::string _name;
    std::string _type;

public:
    Zombie(std::string name, std::string type);
    ~Zombie();
    void announce();
};

#endif