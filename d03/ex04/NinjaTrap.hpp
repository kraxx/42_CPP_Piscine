#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class NinjaTrap : public virtual ClapTrap {

public:

    NinjaTrap();
    NinjaTrap(std::string name);
    NinjaTrap(NinjaTrap const& rhs);
    NinjaTrap& operator=(NinjaTrap const& rhs);
    virtual ~NinjaTrap();

    void meleeAttack(std::string const& target);
    void ninjaShoebox(std::string const& target);
};

#endif