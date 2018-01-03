#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony {
    int         _age;
    std::string _name;
    std::string _owner;

public:
    Pony(int age, std::string name, std::string owner);
    ~Pony();
};

#endif