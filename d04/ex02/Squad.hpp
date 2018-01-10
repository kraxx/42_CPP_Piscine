#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad {

public:

    Squad();
    Squad(Squad const& rhs);
    ~Squad();

    Squad& operator=(Squad const& rhs);

    int           getCount() const = 0;
    int           push(ISpaceMarine* x) = 0;
    ISpaceMarine* getUnit(int n) const = 0;
};

#endif