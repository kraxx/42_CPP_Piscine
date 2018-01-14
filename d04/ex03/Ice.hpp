#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {

public:

    Ice();
    Ice(Ice const& rhs);
    Ice& operator=(Ice const& Ice);
    ~Ice();

    AMateria* clone() const;
    void      use(ICharacter& target);
};

#endif