#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {

private:

    std::string _name;
    AMateria*   _materia[4];

    Character();

public:

    Character(std::string name);
    Character(Character const& rhs);
    Character& operator=(Character const& rhs);
    ~Character() {};
    
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif