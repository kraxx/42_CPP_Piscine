#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

public:

    TacticalMarine();
    TacticalMarine(TacticalMarine const& rhs);
    TacticalMarine& operator=(TacticalMarine const& rhs);
    ~TacticalMarine();

    ISpaceMarine* clone() const;
    void          battleCry() const;
    void          rangedAttack() const;
    void          meleeAttack() const;
};

#endif