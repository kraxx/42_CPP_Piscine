#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria {

protected:

    unsigned int _xp;
    std::string  _type;

    AMateria();

public:

    AMateria(std::string const& type);
    AMateria(AMateria const& rhs);
    AMateria& operator=(AMateria const& rhs);
    virtual            ~AMateria();

    std::string const& getType() const;
    unsigned int       getXP() const;

    virtual AMateria*  clone() const = 0;
    virtual void       use(ICharacter& target);
};

#endif