#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {

public:
    SuperTrap();
    SuperTrap(std::string name);
    SuperTrap(SuperTrap const& rhs);
    SuperTrap& operator=(SuperTrap const& rhs);
    ~SuperTrap();
};

#endif