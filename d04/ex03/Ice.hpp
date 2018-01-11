#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "ICharacter.hpp"

class Ice : public AMateria {

private:

    Ice();

public:

    Ice(std::string const& type);
    Ice(Ice const& rhs);
    Ice& operator=(Ice const& Ice);
    ~Ice();

    Ice*  clone();
    void   use(ICharacter& target);
};

#endif