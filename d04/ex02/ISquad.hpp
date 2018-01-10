#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad {

public:

    virtual               ~ISquad() {};
    virtual int           getCount() const = 0;
    virtual int           push(ISpaceMarine* x) = 0;
    virtual ISpaceMarine* getUnit(int n) const = 0;
};

#endif