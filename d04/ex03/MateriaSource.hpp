#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:

    AMateria* _materia[4];

public:

    MateriaSource();
    MateriaSource(MateriaSource const& rhs);
    MateriaSource& operator=(MateriaSource const& rhs);
    ~MateriaSource();

    void learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const & type);
};

#endif