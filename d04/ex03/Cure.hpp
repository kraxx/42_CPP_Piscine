#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "ICharacter.hpp"

class Cure : public AMateria {

private:

    Cure();

public:

    Cure(std::string const& type);
    Cure(Cure const& rhs);
    Cure& operator=(Cure const& cure);
    ~Cure();

    Cure*  clone();
    void   use(ICharacter& target);
};

#endif