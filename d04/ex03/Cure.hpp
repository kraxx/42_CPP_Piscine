#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {

public:

    Cure();
    Cure(Cure const& rhs);
    Cure& operator=(Cure const& cure);
    ~Cure();

    AMateria* clone() const;
    void      use(ICharacter& target);
};

#endif