#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(ScavTrap const& rhs);
    ScavTrap& operator=(ScavTrap const& rhs);
    ~ScavTrap();
    
    void challengeNewcomer(std::string const& target);
};

#endif